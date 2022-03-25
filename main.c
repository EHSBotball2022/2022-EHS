#include <kipr/wombat.h>

/**
* File: main.c
* Team: EHS Botball Team
* 25 March 2022
* Purpose: To see red or green and move the servo accordingly.
*/
int main()
{
   camera_open(); // opens camera
   while (a_button() == 0) //Creates a loop
   {
 	 camera_update(); // retrieves current image
	 if (get_object_count(0) > 0) //does the camera sees at least 1 red object
	  {
	 	printf("I see red.\n");
	    	int offset, x, y;
			enable_servo(0); // enable servo
			camera_update(); // get most recent camera image and process it
			x = get_object_center(0,0).x; // get image center x data
			y = get_object_center(0,0).y; // and y data
			if(get_object_count(0) > 0) 
			{ 
				display_printf(0,1,"Center of largest blod: (%d,%d) ",x,y);
				offset=5*(x-80); // amount to deviate servo from center
			 	set_servo_position(0,0);
			}
	 		camera_update(); // get new image data before repeating
	 }

	 if (get_object_count(1) > 0) //does the camera sees at least 1 green object
	 {
	 	printf("I see green.\n");
	    int offset, x, y;
		enable_servo(0); // enable servo
		camera_open(); // activate camera
		camera_update(); // get most recent camera image and process it
		x = get_object_center(0,0).x; // get image center x data
		y = get_object_center(0,0).y; // and y data
		if(get_object_count(1) > 0) 
		{ 
			display_printf(0,1,"Center of largest blod: (%d,%d) ",x,y);
			offset=5*(x-80); // amount to deviate servo from center
			set_servo_position(0,2029);
		 	camera_update(); // get new image data before repeating
	 	}
	 }
 	 camera_update();
  }
 return 0;
}

