# push_swap
## Integer sorting algorithm
---
Push Swap is one of the first major projects of 42's common core. The aim of this project is to improve your algorithm skills, and to have a first contact with the concept of complexity. How? Quite easy (or not)...

You must create one or more algorithms that can sort a set of integers, positive and negative, from smallest to largest. You have two stacks, the first with the full set of integers, and the second empty, so you can *push* any integer from the first stack to the second stack to help you with your sorting. Push-swap should chose from the different algorithms which one can sort the set of integers in the least amount of moves.

You have a set of moves you can apply to any of the stacks:
  * __Push__ an integer from one stack to another
  * __Swap__ the first integer of a stack for the second
  * __Rotate__, so the first integer becomes the last of the stack, and the second becomes the first
  * __Reverse rotate__, so the last integer of the stack becomes the first, and the first becomes the second

The objective is to create an algorithm that can sort 500 random integers between -2.147.483.648 and 2.147.483.647 in less than 5.500 moves.

## My choice
I have created three algorithms, the first two are very simple: one algorithm for a set of two integers, and another for a set of three algorithms. The third algorithm (donde está la chicha) is a __costs sorting algorithm__. It asigns a cost to each of the integers depending on it's distance from it's ideal position.
With this cost calculation, I managed to sort any 500 random integers in under 5.000 moves. Do you want to try and improve this mark?

## Clone the repo...
or download the files. You will need make on your PC. Once you have the repo locally, open a terminal in that same directory and type the command:
`make`
This will compile the full project, including my personal C library: libft, which contains a large range of C functions that can help with this project or any other.
Once you have compiled push_swap you can create and ARG with a set of integers of your own choice. In the same directory type the command:
`ARG="50, -60, 1, 2, 4, 78, -1, 0, 4.890.212, (add ints till your dizzy)"`
To execute push_swap with this set of integers, type the command:
`./push_swap $ARG`
o
`./push_swap $ARG | wc -l` if you only want to see how many moves it took to sort this set.

There are fantastic online resources available to play a push_swap game that will help you visualize the process:
[Link](https://vscza.itch.io/push-swap)
or to visualize the real-time execution of your push_swap solution, even to create a set of random integers:
[Link](https://push-swap-visualizer.vercel.app/)

I hope you enjoy messing around with this program. I had great fun creating it!
