Multiple bubbles in a line. bubbles could move left/right
Provide a line of integers, each integer represents the weight of the bubble w[i], w[i]!=0
move right w > 0, move left w < 0
Movement requirements:
1. Two bubbles move towards each other will collide, cannot collide if two bubble move to the same direction/away from each other
2. Collision rules: w bigger will eat w smaller; same w will both disappear
Inputs:
1. Line of integers w, separated by space, len(w) < 100 , w[i] < 100000
Outputs:
1. Final array w of the line
