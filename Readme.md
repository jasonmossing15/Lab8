# Lab 8 - The Maze

This library deals with the running the ECE382 Robot through a maze.

## Concepts Needed

You need two main items in this lab:
 - Sensors library
 - Robot movement library

Both of these are in this repo.

## The Code

The Robot is a left wall follower, meaning it moves toward the left wall unless it is too close to the wall. In addition if the robot moves to close to the wall directly in front of it, it will back-up breifly then turn 90 degrees to the right. Some changes had to be made in the motor movement library to work. This was to include:
 - changing the duty cycle to slow down the robot
 - creation of two new functions: `veerLeft();` and `veerRight();`

The veer functions have one motor go forward at the normal speed and slow the the other wheel to replicate a veer. This idea was given to me by Caleb Ziegler (the man, the myth, the legend). 

## Documentation and License

Anyone is allowed to use this code as long as you document. Caleb Ziegler helped me a lot on this assignment, so I suggest you just look at his. Here is a link to his [repo](https://github.com/czig/Lab8).
