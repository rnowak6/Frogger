4/18/2018 I am trying to undestand Allegro. I had some issues downloading it. Currently trying to figure out how to use it.
Since I am still trying to learn how to use Allegro, I created an outline with a general idea of how I want my code to look 
a what methods I might wants to use. I tried using code from Snake but I am not sure what Allegro provides me with so that
part is incomplete because it is missing multiple components that Snake had but I am still trying to figure it out.
I also have empty images that I will later use in my game once I figure out how to incorporate 
them. I created a simple main by using Allegro to generate a window that says "Frogger".
I know that there is not a lot done but I am currently researching and trying to figure out how to use Allegro. Once that is done, 
it will be a lot easier for me to start writing actual code for the game.

4/23 I created an image of a road and was able to display it with Allegro. My next step is to create a sprite which would be my frog and be able to display it and eventually move it.

4/24 I was able to display a sprite aka my frog and the user is able to use the arrow keys to move it. Next I will be trying to use the same concept for moving the frog but for moving cars and to have them move continuously on the screen. A few things that I will have to improve about the frog will be keeping it within the bounds of the window and adding sound every time it jumps.

4/25 I was able to display and move the cars on screen. So far I only have two and I will have to figure out how to add more without having to create additional images. I was having some minor issues with displaying images but that was fixed by using full file paths.

4/26 Was able to display both the frog and the cars on the screen together however I have a problem because either only my frog moves or only the cars move and I'm trying to figure out what I'm doing wrong and what to do to make both actions occur at the same time.

4/27 Tried messing around with the code to get the frog and cars to both be able to move but sadly so far no progress

4/29 Got both the cars to move and the frog to move! I tried moving some things around and to put them in my ofApp but I need additional help

4/30 I created bounds for the frog so it is not able to move off the screen. Only the cars can move off screen. I could not get my code to break up and be moved to ofApp so I will be keeping it in main until I can split it up into other classes

5/1 Added sound for every time the frog moves and if it wins. When it wins a window is displayed congratulating the user. For the window, I will try to have an option to restart the game so that the user can play the game again. I tried getting collision detection to work and no matter what I try it is not working. I also tried to move things out of the main class but I am getting too many errors. I might end up leaving it all in main but just splitting it up by methods because I need it to work. 

5/2 Finally got collision detection to work! It is not the most efficient thing in the world but it's going to have to work. I also was able to display a window and play sound when the user loses. I tried breaking up my code down more into seperate methods. The code displays a win and a loss. It also plays sound and collision detection works however it seems that some rounds it picks up on it better than other times which may suggest that Visual Studio is not the best choice in the future to create games.
