# 42 Projects:
## Description:

<p>
  These are the projects developed during the self taught process method developed at 42 Telefónica CE school.
  They are developed mainly in C with the use of Makefiles to help building the projects.
</p>

## libft:

<p>
  This is a library focused on implementing basic functions from standard libraries (stdlib, stdio, ...) from scratch, which are then used in later projects. 
  These are very focused on error checking and exception handling, since they are reused multiple times from inside and outside the project.
  Some data structures like linked lists and basic functions along them are also implemented from scratch.
</p>

## print_ft:

<p>
  This project implements the classic printf function from scratch, with basic functionality, avoiding some formatting that is included in the original printf.
</p>

## get_next_line:

<p>
  This project implements the classic get_next_line function from scratch, with special focus in file descriptors and error/memory handling.
</p>

## push_swap:
<p>
  This project uses stacks and sorting algorithms that are limited to certain operations with the final goal of optimization. The idea is to sort with the least amount of operations one sequence of integers usign two stacks with the limited following operations:
  <li>sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).</li>
  <li>sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).</li>
  <li>ss : sa and sb at the same time.</li>
  <li>pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.</li>
  <li>pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.</li>
  <li>ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.</li>
  <li>rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.</li>
  <li>rr : ra and rb at the same time.
  <li>rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.</li>
  <li>rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.</li>
  <li>rrr : rra and rrb at the same time.</li>
</p>

## so_long:
<p>
  This project is the development of a simple videogame level using a low-level graphics library called MLX, internal to the school; the libft library and implements and map reading from a text file, which is imported into the game to generate a level where the player needs to collect all resources before going to the exit.
  This project also highly focuses on memory and error management, as well as implementing algorithms like Dijkstra's to check if the map provided has indeed the potential to be solved.
</p>

## pipex:
<p>
  This project recreates the use of pipes in the terminal command line interface, with the theory behind processes and managing them, with the proper use of important functions like fork(), execve, dup and dup2 for file descriptor duplication and management...
</p>
