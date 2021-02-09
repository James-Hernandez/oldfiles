So my midterm was the rocket one. As of now I have completed all points except the last one making the collision happen.
1) So for the first point on the parallax I used the scroll function to make it move from top to bottom and just said "down" in the string.

2)for the auto animated Rocket head upward I made I moded a sprite sheet i found online in photoshop for what i needed for the midterm, the picture wasnt a perfect png sprite sheet
so i had to cut images out and make a transparent background for the sheet. and to make it head up upward i had the default image of the sprite sheet at first launch of the application to 
to initialy have the image of rocket sprite sheet pointing upward.

3) to make the left and right keys to move the rocket across the screen i made some inputs in the input file and had the keys trigger actiontrigger function to translate the the 
player/rocket across the screen in the corresponding direction. I not only made keys for the left and right but also for the up and down keys as well so when you hit the up and down keys
the player/rocket will move in that direction. i also made it to where if the player/rocket is translated across a certain point "mainly the window frame" the rocket will reappear on 
the opposite side of the screen like how they do in pac man. I also added some other functions to have the player "Grow" with the input 'W' and "Shrink" with the 'S' key i also 
made it to where the player/rocket can rotate around with the input of 'D' for CW motion and 'A' for CCW motion. I wanted to make it like the old game asteroids.

4) so to make the objects move from top to bottom i made a collision function and put the function in draw objects and constantly update the yPos. I also made it to where 
if the yPos goes beyond the bottom of the frame it will translate back to the top and fall back down in a continous loop.

5) The collision is what i had trouble with the most, I still havent quite figured it out yet but what what my thought process is that i could make so when the objects vertex coordinates
are equal to the players positon then the object will be translated accordiningly. But I still cant quite figure out how to do that yet. I made a collision function and i am passing in
the player/rocket x and y position and trying to compare that with the objects coordinate positions but its not working.  
 


1) Use horizontal parallax moving from top to bottom
2) Use auto animated Rocket head upward
3) Make ‘Left’ and ‘Right’ keys to move the Rocket on the screen
4) Use animated moving objects from top to bottom in random positions
5) Make objects bounce and move in appropriate directions when collide with the Rocket