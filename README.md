# README

*This project has been created as part of the 42 curriculum by ecantu-p*

# Description

Push-Swap project aims to teach about sorting data algorithmic. The goal is to write a C program called push_swap that calculates and displays the shortest sequence of Push-Swap rules needed to sort a given set of integers. 

| Program Name | push_swap |
| --- | --- |
| Turn in files | Makefiles, *.h, , *.c |
| Makefile | NAME, all, clean, fclean, re |
| Arguments | stack a: A list of integers |
| External functs. | malloc |
|  | free |
|  | read |
|  | write |
|  | exit |
|  | ft_printf |
| Libft authorized | Yes |
| Description | Sort stacks |

### Push-Swap rules

- Two stacks named a and b with the initial setting:
    - Stack `a` containing a random number of unique negative and / or positive integers.
        - This means from -2147483648 to 2147483647
    - Stack `b` being empty.
- The final state is a sorted stack a in ascending order while b ends empty.
- Available operations
    - `sa`: (swap a): Swap the first 2 elements at the top of stack a.
        - Do nothing if there is one or less elements in the stack
    - `sb`: (swap b); Swap the first 2 elements at the top of stack b.
        - Do nothing if there is one or less elements in the stack
    - `ss`: `sa`  and `sb`  at the same time.
    - `pa`  (push `a`): Take the first element at the top of `b` and put it a the top of `a`.
        - Do nothing if `b` is empty.
    - `pb` (push `b`): Take the first element at the top of `a`  and put it a the top of `b`.
        - Do nothing if `a` is empty.
    - `ra` (rotate `a`): Shift up all the elements of stack `a` by 1.
        - The first element becomes the last one.
    - `rb` (rotate `b`): Shift up all the elements of stack `b` by 1.
        - The first element becomes the last one.
    - `rr`:`ra` and `rb`  at the same time.
    - `rra` (reverse rotate a): Shift down all elements of stack `a`  by 1.
        - The last element becomes the first one.
    - `rrb` (reverse rotate b): Shift down all elements of stack `b` by 1.
        - The last element becomes the first one.
    - `rrr`: `rra` and `rrb` at the same time.

# Instructions

1. To evaluate this project first you must have cloned its git repository.
2. There is a Make file to build the library. The following rules are available to build the library:
*all*, *clean*, *fclean* and *re*.
    1. make *all*: Builds the library form 0.
    2. make *clean*: Removes the object files.
    3. make *fclean*: Removes additional to *clean* the static library file.
    4. make *re*: Runs *clean* and rebuilds the library.
    
    After building the library, verify the c files against norminette.
    
3. The program name is`push_swap`. It only accepts an integer list as arguments input. 
    1. run as follows:
        
        ```bash
        $> ./push_swap 2 1 3 6 5 8
        ```
        
        ```bash
           sa
           pb
           pb
           pb
           sa
           pa
           pa
           pa
        ```
        
4. If non-integers are input, the program displays `Error\n`. 
    1. error example
        
        ```bash
        $> ./push_swap 0 one 2 3
        	 Error
        ```
        
5. If no integer list is typed, the program returns to prompt. 
6. Check the project validation with the aid of the `./checker` program. Run:
    
    ```bash
    $> ARG="2 1 3 6 5 8"; ./push_swap $ARG | wc -l  \\ wc -l count lines
       6
    ```
    
    ```bash
    $> ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker_OS $ARG
       OK
    ```
    

## Bonus

1. To run the bonus part, do:
    1. make bonus
2. To use it and validate an input do:

```jsx
$>./checker 3 2 1 0
```

```jsx
$>ARG="2 1 3 6 5 8"; ./checker $ARG 
```

1. On success the output is: `OK` on fail is `KO` and error is `"Error"`

# Resources

- Reese, Richard M. Understanding and using C pointers: Core techniques for memory management. " O'Reilly Media, Inc.", 2013.
- Cormen, Thomas H., Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. *Introduction to algorithms*. MIT press, 2022.
- Reese, Richard M. Understanding and using C pointers: Core techniques for memory management. " O'Reilly Media, Inc.", 2013.
- https://en.wikipedia.org/wiki/Sorting_algorithm
- https://en.wikipedia.org/wiki/Quicksort
- https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
- https://github.com/gleal42/Makefile-Tutorialhttps://medium.com/@bugrahankaramollaoglu/makefile-tutorial-e95b25078633
- https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/
- https://en.wikipedia.org/wiki/Counting_sort
- https://en.wikipedia.org/wiki/Radix_sort
- https://www.sanfoundry.com/c-tutorials-doubly-linked-list/
- https://www.tutorialspoint.com/data_structures_algorithms/stack_algorithm.htm
- https://intellipaat.com/blog/tutorial/c-tutorial/doubly-linked-list-in-c/

---

# Main Algorithm, overview only.

1. Initialize variables and solution matrix.
2. Initialize counters for comparison and aggregation in the solution matrix.
    1. There are 6 counters in the algorithm
        1. x = ra.
        2. y = rra.
        3. k = rb for ra(x).
        4. l = rrb for ra(x).
        5. m = rb for rra(y).
        6. n = rrb for rra(y).
3. Validate that each input element is a valid integer.
4. Create stack_a with all elements.
5. Determine the mean and standard deviation. 
6. Solve the sorting based on:
    1. Sort two numbers. Do sa if required, otherwise exit.
    2. Sort three numbers. Do a hard coded sort in stack a.
    3. Sort 5 numbers. Do limited sorting. Do not initialize stack_b.
    4. Sort less than 24 numbers. Do limited sorting and initialize stack_b.
    5. Sort more than 23 numbers. Do full sort sorting and initialize stack_b.
7. Clean dynamically allocated memory.

## Sorting step 6.

1. Do sa if required.
2. Do hard coded sort. 
    
    With *a* defined as a vector with *i* values:
    
    ```jsx
    if (i < i + 1)
    {
    	if (i + 1 < i + 2)
    		break;
    	else if (i < i + 2)
    	{
    		ra;
    		sa;
    		rra;
    	}
    	else
    		rra;
    }
    else if (i < i + 2)
    	sa;
    else if (i + 1 < i + 2)
    	ra;
    else
    {
    	sa;
    	rra;
    }
    ```
    
3. Do limited sorting to 5 elements.
    - Move two nodes to stack_b.
    - Do step b in stack_a.
    - Return the two nodes in stack_b to stack a in the proper location. Do either ra or rra accordingly before pa.
4. Do limited sorting to 23 elements and initialize stack_b.
    1. Stack_b initialization
        - With j *= -5, d*efine c_d, cluster delimited,  value as :
            
            $avg = \frac{\sum_{i = 0}^{n-1} a[i]}{n}$
            
            $stdev = \sqrt\frac{\sum_{i = 0}^{n-1} (a[i] - avg)^2}{n - 1}$
            
            $c_d = avg - (j*\frac{stdev}{3})$   
            
        - If doing pb of the *i* stack value is less than 70 moves, do pb otherwise increase the *j* value by 1 until it does.
    2. For each *i* value in *stack_a* calculate calculate the solution matrix. The solution matrix is composed of:
        - Key value(i), x,  y, k, l, m, n, Solution and Solution Value.
            - Where solution represents the lower costing value of doing ra(x) or rra(y) with its combination of rb and rrb. The total cost is represented by the Solution value.
        - The same approach as with stack_b initialize step is followed. The element to move in stack_a are limited by the cluster delimiter calculation. It starts at j = -5 and continues with increments until the given condition on minimum values in stack a is met.
        
            The solution matrix is:
            |	i	|	x	|	y	|	k	|	l	|	m	|	n	|	Solution	|	Solution Value	|
            |	---	|	---	|	---	|	---	|	---	|	---	|	---	|	---	|	---	|
            |	-1	|	24	|	218	|	0	|	0	|	0	|	0	|	   x      	|	      24     	|
            |	0	|	105	|	324	|	0	|	0	|	0	|	0	|	   x      	|	      105    	|
            |	1	|	132	|	367	|	0	|	0	|	0	|	0	|	   x      	|	      132    	|

    3. The solution matrix is ascending sorted in its Solution Value’s to have the cheapest solution at the top.  As this matrix is a double linked list, it is the head value. 

            Before solution selection.The solution matrix i:
            |	i	|	x	|	y	|	k	|	l	|	m	|	n	|	Solution	|	Solution Value	|
            |	---	|	---	|	---	|	---	|	---	|	---	|	---	|	---	|	---	|
            |	-1	|	0	|	1	|	0	|	53	|	0	|	109	|	   x      	|	      53     	|
            |	0	|	1	|	2	|	59	|	0	|	17	|	0	|	   y      	|	      19     	|
            |	1	|	2	|	3	|	53	|	0	|	31	|	0	|	   y      	|	      34     	|
            |	2	|	3	|	4	|	44	|	0	|	38	|	0	|	   y      	|	      42     	|
            |	3	|	4	|	5	|	50	|	0	|	0	|	62	|	   x      	|	      54     	|
            |	4	|	5	|	6	|	36	|	0	|	0	|	75	|	   x      	|	      41     	|
            |	5	|	6	|	7	|	0	|	2	|	0	|	61	|	   x      	|	      8      	|
            |	6	|	7	|	8	|	41	|	0	|	0	|	113	|	   x      	|	      48     	|
            |	7	|	8	|	9	|	7	|	0	|	22	|	0	|	   x      	|	      15     	|
            |	8	|	9	|	10	|	0	|	66	|	30	|	0	|	   y      	|	      40     	|
            |	9	|	10	|	11	|	30	|	0	|	41	|	0	|	   x      	|	      40     	|
            |	10	|	11	|	12	|	21	|	0	|	22	|	0	|	   x      	|	      32     	|
            |	11	|	12	|	13	|	0	|	13	|	0	|	53	|	   x      	|	      25     	|
            |	12	|	13	|	14	|	0	|	21	|	0	|	10	|	   y      	|	      24     	|
            |	13	|	14	|	15	|	2	|	0	|	0	|	11	|	   x      	|	      16     	|
            |	14	|	15	|	16	|	0	|	21	|	0	|	21	|	   x      	|	      36     	|

            After solution selection. The solution matrix is:
            |	i	|	x	|	y	|	k	|	l	|	m	|	n	|	Solution	|	Solution Value	|
            |	---	|	---	|	---	|	---	|	---	|	---	|	---	|	---	|	---	|
            |	5	|	6	|	7	|	0	|	2	|	0	|	61	|	   x      	|	      8      	|
            |	7	|	8	|	9	|	7	|	0	|	22	|	0	|	   x      	|	      15     	|
            |	13	|	14	|	15	|	2	|	0	|	0	|	11	|	   x      	|	      16     	|
            |	0	|	1	|	2	|	59	|	0	|	17	|	0	|	   y      	|	      19     	|
            |	12	|	13	|	14	|	0	|	21	|	0	|	10	|	   y      	|	      24     	|
            |	11	|	12	|	13	|	0	|	13	|	0	|	53	|	   x      	|	      25     	|
            |	10	|	11	|	12	|	21	|	0	|	22	|	0	|	   x      	|	      32     	|
            |	1	|	2	|	3	|	53	|	0	|	31	|	0	|	   y      	|	      34     	|
            |	14	|	15	|	16	|	0	|	21	|	0	|	21	|	   x      	|	      36     	|
            |	8	|	9	|	10	|	0	|	66	|	30	|	0	|	   y      	|	      40     	|
            |	9	|	10	|	11	|	30	|	0	|	41	|	0	|	   x      	|	      40     	|
            |	4	|	5	|	6	|	36	|	0	|	0	|	75	|	   x      	|	      41     	|
            |	2	|	3	|	4	|	44	|	0	|	38	|	0	|	   y      	|	      42     	|
            |	6	|	7	|	8	|	41	|	0	|	0	|	113	|	   x      	|	      48     	|
            |	-1	|	0	|	1	|	0	|	53	|	0	|	109	|	   x      	|	      53     	|
            |	3	|	4	|	5	|	50	|	0	|	0	|	62	|	   x      	|	      54     	|

    4. Once the cheapest solution is selected apply the appropriate rules combination. 

    5. Continue with this loop until 5 elements are left in stack a. 

5. Perform the steps as with sorting 5 elements in previous level step c.

6. For more than 23 numbers follow the same steps as in the previous  case, except that it stops when 23 elements are in the stack_a left. Then it follow the 5 elements algorithm. 

# Developed Functions

### push_swap_advance_rules.c

- `void    ps_rab(*t_stack* **a*, *t_stack* **b*)`
    - Runs rr rule.
- `void    ps_rrab(*t_stack* **a*, *t_stack* **b*)`
    - Runs the rule.

### push_swap_basic_rules.c

- `void    ps_p(*t_stack* **stack_dst*, *t_stack* **stack_src*, char *stack_dest_name*)`
    - Runs pa or pb rule.
- `void    ps_r(*t_stack* **stack*, char *stack_name*)`
    - Runs ra or rb rule.
- `void    ps_rr(*t_stack* **stack*, char *stack_name*)`
    - Runs rra or rrb rule.
- `void    ps_s(*t_stack* **stack*, char *stack_name*)`
    - Runs sa or sb rule.

### push_swap_endroutine.c

- `void    ps_free(void ***ptr*)`
    - Own implementation of free. Ensures pointer = NULL.
- `void    ps_clean(void ***ptr*, *size_t* *ptr_len*)`
    - Cleans a list.
- `void    ps_stack_clean(*t_stack* **stack*, void (**del*)(void **))`
    - Cleans the stack. Used at the program’s end.
- `void    ps_endroutine(int *argc*, *t_stack* *stack_a*, *t_stack stack_b*, *t_stack_solutions* **solutions*)`
    - Last routine to clean all memory locations at the end.

### push_swap_error_check.c

- `long    int ps_atoli(const char **nptr*)`
    - An atoi but with long integers.
- `char    **ps_checker_arg(char ***p_argv*)`
    - Validates that each argument is a unique integer in the input array.
- `char    **ps_checker(int *argc*, char **argv*[])`
    - A function that handles the input validation.
- `int     ps_error(char **str*, char ***ptr*, *size_t* *ptr_len*)`
    - Error management when, there is an error.
- `void    ps_free_p_argv(int *argc*, char ***p_argv*)`
    - An error handler to free memory on the created array after the input validation

### push_swap_error_check_utils.c

- `int     ps_isduplicate(char **slv*[], *size_t* *size*)`
    - Evaluates if a given integer in an array already exist.
- `int     ps_isint(char **nptr*)`
    - Verifies if a string is an integer
- `int     ps_initialize_p_argv(*t_stack_solutions* **sol*, int *argc*, char ***argv*)`
    - Validates argv input and places its content in a double pointer.

### push_swap_matrix_solution.c

- `void    ps_check_solution(*t_stack* *stack_a*, *t_stack_solutions* *sol*)`
    - Validates if stack_a has the correct ascending order in its values.
- `int     ps_mtx_sol(*t_stack_solutions* **sol*)`
    - Creates a matrix with the ascending sorted values, returns 0 on success and -1 if it fails.

### push_swap_printf.c

- `void    ps_display_values(char **names*[])`
    - Given a double char pointer,  prints each string element.
- `void    ps_printf_both_stacks(*t_stack* **stack_dst*, *t_stack* **stack_src*)`
    - Prints the current state of the two stacks.
- `void    ps_printf_mtx(int ***mtx*)`
    - Prints the solved matrix
- `void    ps_printf_solution(*t_node_solution* **node*)`
    - Prints the solution matrix.
- `void	ps_printf_stack(t_node *stack)`
    - Print the elements of the stack.

### push_swap_solutions.c

- `void    ps_select_solution(*t_stack_solutions* **stack*)`
    - A function to select from the solution matrix (linked list) the lowest value/lower cost to use. Calculates the value from x and y which are ra and rra and k l / m n. Which are rb rrb for ra and, rb and rrb for rra.
- `int     ps_isfound_solution(*t_counters* **count*, *t_stack* **stack_b*, *t_stacks* **s*)`
    - When a solution is not found, initializes the variables to create the next tuple in the solution matrix.
- `void    ps_xkl(*t_stack* **stack_a*, *t_stack* **stack_b*, int *x*, int *k*, int *l*)`
    - Applies the rules based on the x, k and l values. x refers to the number of times ra is applied. k refers to the number of times rb is applied.  l refers to the number of times rrb is applied.
- `void    ps_ymn(*t_stack* **stack_a*, *t_stack* **stack_b*, int *y*, int *m*, int *n*)`
    - Applies the rules based on the y, m and n values. y refers to the number of times ra is applied. m refers to the number of times rb is applied.  n refers to the number of times rrb is applied.

### push_swap_solve_compare.c

- `int     ps_compare_k_m(int *a*, *t_stack* *stack_b*)`
    - Determines the number of times the rb function should be applied given a value in stack_a. The solution is in descending order.
- `int     ps_compare_k_m_reverse(int *a*, *t_stack* *stack*)`
    - Determines the number of times the rb function should be applied given a value in stack_a. The solution is in ascending order.
- `int     ps_compare_l_n(int *a*, *t_stack* *stack_b*)`
    - Determines the number of times the rrb function should be applied given a value in stack_a. The solution is in descending order.
- `int     ps_compare_l_n_reverse(int *a*, *t_stack* *stack*)`
    - Determines the number of times the rrb function should be applied given a value in stack_a. The solution is in ascending order.
- `int     ps_isinstdev(*t_node* **stack_a*, int *std*)`
    - Checks if a given integer is inside the evaluated cluster.

### push_swap_solve_counters.c

- `void    ps_advance_solution(`*t_counters* **counters*`)`
    - Set the initial values for each element of the solution matrix
- `void    ps_initialize_counters(*t_counters* **count*)`
    - Initializes the counters values
- `void    ps_initialize_stack(*t_stack* **stack*)`
    - Initialize a data stack.
- `int ps_solve_counters(*t_stacks* **s*, *t_counters* **count*, *t_stack_solutions* **sol*)`
    - Calculates the k, l, m and n values.

### push_swap_solutions_node.c

- `*t_node_solution*    *ps_ini_solution_node(*t_counters* *count*)`
    - Initialize the first matrix (linked list) solution’s node.
- `void    ps_reset_key(*t_node* **stack*)`
    - A function to reset the index key in ascending order.
- `void    ps_reverse_reset_key(*t_node* **stack*)`
    - A function to reset the index key in descending order.

### push_swap_solutions_stack.c

- `void    ps_add_tail_solution(*t_stack_solutions* **stack*, *t_node_solution* **node*)`
    - A function to add a node to the matrix solution (linked list) to the list tail.
- `void    ps_clean_solution(*t_stack_solutions* **stack*, void(**del*)(void **))`
    - Cleans the matrix (linked list) solution.
- `void    ps_ini_solution_stack(*t_stack_solutions* **stack*, *t_counters* *count*)`
    - A function to initialize the solution matrix (linked list).
- `void    ps_initialize_stack_solution(*t_stack_solutions* **stack*)`
    - Initialize the matrix (linked list) solution.
- `void    ps_sort_solution(*t_stack_solutions* **statck*)`
    - Performs a bubble sorting on the matrix (linked list) solution.

### push_swap_solve_selection.c

- `void    ps_solve(*t_stack* **stack_a*, *t_stack* **stack_b*, *t_stack_solutions* **sol*, *t_counters* **count*)`
    - Solving function for an input greater than 5 elements.
- `void     ps_solve_2(*t_stack* **stack_a*)`
    - Solving function for an input equal to two elements.
- `void    ps_solve_3_asc(*t_stack* **stack*, char *stack_name*)`
    - Solves three nodes in ascending order. Only these nodes must exist in the stack.
- `void ps_solve_5(*t_stack* **stack_a*, *t_stack* **stack_b*, *t_stack_solutions* **sol*, *t_counters* **count*)`
    - Solving function for an input equal to 5
- `void     ps_solve_selection(*t_stack* **stack_a*, *t_stack* **stack_b*, *t_stack_solutions* **sol*, *t_counters* **count*)`
    - Determines which solution function to call based on the input element size.

### push_swap_solve_utils_rules.c

- `int     ps_sort_a_r(*t_stack* *stack*)`
    - Determines how many times ra needs to be applied to finish with the smallest element at the head of stack_a.
- `int     ps_sort_a_rr(*t_stack* *stack*)`
    - Determines how many times rra needs to be applied to finish with the smallest element at the head of stack_a.
- `int     ps_sort_b_r(*t_stack* *stack*)`
    - Determines how many times rb needs to be applied to finish with the largest element at the head of stack_b.
- `int     ps_sort_b_rr(*t_stack* *stack*)`
    - Determines how many times rrb needs to be applied to finish with the largest element at the head of stack_b.

### push_swap_solve_utils_stack_b.c

- `void     ps_solve_counter_stack_b(*t_counters* *count*, *t_stack* **stack_b*)`
    - A step in preparation to return the  stack_b values to stack_a. Determines to do rb or rrb depending on the lowest value among them.
- `void      ps_solve_return_to_stack_a(*t_counters* *count*, *t_stack* **stack_a*, *t_stack* **stack_b*, *t_stack_solutions* *sol*)`
    - Returns the stack_b values to stack_a.
- `void     ps_sol_run(*t_stack* **stack_a*, *t_stack* **stack_b*, *t_stack_solutions* **sol*)`
    - Selects the cheapest solution and applies it.

### push_swap_solve_utils.c

- `void     ps_solve_3_asc_algorithm(*t_stack* **stack*, char *stack_name*)`
    - Solve algorithm for  a 3 element stack in ascending order.
- `void     ps_isrun(*t_counters* **count*, *t_stack* **stack_b*, *t_stack_solutions* **sol*, *t_stacks* **s*)`
    - Determines to do pb or run the solution algorithm.
- `void    ps_solve_stack_a_limit(*t_counters* **count*, *t_stack_solutions* **sol*, *t_stack* **stack_a*, *t_stack* **stack_b*)`
    - Performs either ra or rra before doing pa. It helps  when stack_b values are returning back to stack_a.
- `void     ps_solve_stack_a(t_counters count, t_stack *stack_a)`
    - Calculates ra and rra quantities to do in ps_solve_stack_a_limit.
- `void     ps_solve_stack_b(*t_stack* **stack_a*, *t_stack* **stack_b*, *t_stack_solutions* **sol*, *t_counters* **count*)`
    - Main algorithm to solve stack_b for an input quantity greater than 5 elements.

### push_swap_solve.c

- `void    ps_ini_sort_1_node(*t_stack* **stack_dst*, *t_stack* **stack_src*)`
    - Does pb to initialize stack_b depending on the number of ra or rra to perform.
- `void     ps_ini_sort_1_node_x_y_calc(*t_stack* **stack*, int **x*, int **y*, int *j*)`
    - Determines the quantity of ra and rra that do not require more than 70 steps to initialize stack_b.
- `void    ps_initialize_ranking(*t_node* **head*, *t_stack_solutions* *sol*)`
    - Exchange the value from each node with the key value on the sorted matrix (mtx).
- `void    ps_sol_ini(*t_stack* **stack_a*, *t_stack_solutions* **sol*, *t_counters* **count*)`
    - Starts with the solution, determines the cluster delimiter value (c_d), determines if sa is possible and starts the solving algorithm.

### push_swap_utils

- `*size_t*  ps_dptrlen(const char ***str*)`
    - Returns a double char pointer length.
- `void    ps_initialize_avg_std(*t_stack* **stack_a*, *t_stack* **stack_b*, int ***mtx*)`
    - Calculates the average and the standard deviation on the integers input.
- `int    ft_mean(int ***mtx*, *size_t* *mtx_len*)`
    - A function to calculate the average from a (1x2) matrix. The first column is for the key index and the second column is for the vector values.
- `long long int   ft_pseudo_sqrt(long long int *nb*)`
    - Calculates the square root of a integer, no floating point. Therefore there is no precision.
- `int    ft_pseudo_stdev_s(int *mtx_len*, int ***mtx*, int *average*)`
    - Calculates the standard deviation from a population with integer precision. Same problem as with ft_pseudo_sqrt.

### push_swap_utils_node

- `void    ps_add_head(*t_stack* **stack*, *t_node* **node*)`
    - Adds a new node to the stack head.
- `void    ps_add_tail(*t_stack* **stack*, *t_node* **node*)`
    - Adds a node to the stack tail.
- `void    ps_node_clean(*t_node* ***node*, void (**del*)(void **))`
    - Cleans a data node content.
- `*t_node*  *ps_initalizate_node(int *key*, char **data*)`
    - Initializes data node.
- `*t_node*  *ps_node_last(*t_node* **list*)`
- Returns the last node in a list.

### push_swap_utils_stack

- `void    ps_initialize(*t_stack* **stack*, int *key*, char **data*)`
    - Adds each element to satack_a.
- `void    ps_initialize_stack(*t_stack* **stack*)`
    - Initialize the data stack.
- `*t_node*  *ps_pop_bottom(*t_stack* **stack*)`
    - It returns the stack bottom node and adjust the information in the stack
- `*t_node*  *ps_pop_top(*t_stack* **stack*)`
    - It returns the stack header node and adjust the information in the stack
- `void    ps_stack_push(*t_stack* **stack*, *t_node* **node*)`
    - It pushes a t_node to the t_stack.

### push_swap_solve_counters_selection.c

- `void    ps_select_counters(*t_counters* **count*, *t_stack* **stack_b*, *t_stacks* **s*)`
    - Determine which counter, either rb or rrb do, but does not applies it.
- `void    ps_select_counters_rrb(*t_counters* **count*, *t_stack* *stack_b*, *t_stacks* **s*)`
    - Verifies if rrb is not a better solution.

### push_swap_bonus

- `void    ps_check_solution_bonus(*t_stack* *stack_a*, int ***mtx*, *size_t* *p_argv_len*)`
    - Function that runs the bonus requirements

# Examples

### 100 numbers
```bash
arg="563950 907614 226501 183849 827452 528047 41590 14819 561800 207911 57421 488282 822171 172483 523375 238094 814001 891799 908158 864469 936830 666707 894935 975191 43600 664930 165840 987979 290397 711717 -97693 -32747 443335 618759 489094 12051 173350 461328 516099 921194 768345 122383 402175 433959 -48776 563230 989127 960084 188642 244610 794426 519439 907510 975074 136742 926357 -13888 645063 73690 -92082 302483 112123 312335 275307 40813 488253 64850 244502 -99887 252274 377710 107032 889935 450187 595929 342710 805380 837108 118856 -33242 557117 692479 235234 974623 585948 -15316 37888 577373 964526 911297 385363 901948 738106 999766 711942 5420 646723 344838 553320 752254";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="136743 -69910 798229 689557 966200 282483 238064 517299 753895 990348 322028 763238 981904 -98322 943491 -12983 257378 849076 46172 702195 159033 439822 82061 263647 237776 -93974 362927 -75804 908409 980195 874075 687827 205191 -18950 555918 792711 396987 479120 480960 58413 564159 713587 877182 272550 17299 192093 719557 369666 -79643 783580 106995 914673 600826 -13547 -63178 184088 930199 985687 977058 665756 793558 20442 -99099 187410 882437 643567 192553 25183 822740 354712 582238 187864 338450 430173 223737 165974 432448 244033 739589 743729 611349 795473 461249 -78317 -78147 784902 672249 493898 434794 557142 76914 136477 63129 437739 176458 217370 699383 34109 912027 318710";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="550461 -99118 250995 43878 199021 293221 798286 406841 -1831 554103 864974 318553 100015 360191 235048 186156 -82166 696438 790187 252960 854378 905868 948969 286510 428028 625556 180352 318947 577793 717048 989298 590025 492280 732935 154520 59349 619596 415647 428428 43138 790444 427356 894633 771597 465281 986116 389670 795784 -9748 532510 373131 21220 832584 932009 549600 967870 -6032 741338 735663 754261 692022 323006 314008 945044 926988 823965 -71283 -27470 893632 -25515 396246 893968 -7054 686854 864477 541272 796496 371214 453395 681531 9329 180984 122952 -83165 973690 516435 560402 668515 859237 663193 -10056 -44785 -95551 494543 927733 595394 177756 -81830 121431 794692";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="137707 254108 781461 594037 851049 825633 333108 419408 355083 298784 105454 297874 41862 676687 293958 106749 241107 223030 360068 894076 288295 81916 953269 530059 469261 261260 809937 638595 783129 477475 180632 184430 462945 194292 807070 15487 6789 543612 812535 -89289 373723 116370 66876 456143 945013 109979 456300 929393 608570 34105 291257 447830 -49758 105923 733154 156398 392630 135479 884600 665597 439254 690406 502214 954484 523129 524259 8774 40138 988982 915044 244705 530731 750197 496190 138392 159189 -14996 56211 41770 628716 712146 721659 574189 212454 296568 837724 301148 293293 620399 -62693 592430 -50799 432406 1689 733362 617765 94750 242777 -56130 609789";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="227839 -89435 997999 601139 417930 710356 42959 -61556 720708 291955 764141 67106 899365 68535 405163 936106 114595 332963 393568 740264 36669 427188 650306 533915 -33622 -26227 880377 417205 998083 667884 -65147 39850 92434 654755 61066 777223 -8265 730427 968434 685962 690178 84663 767137 861923 63345 894135 412338 384363 152951 830548 439326 124188 940142 708439 978125 -69433 929056 327441 52230 -67649 655377 599913 394873 807914 607969 -89780 732384 520938 80130 571740 508961 91210 149235 728149 526399 28229 411911 449333 321580 764548 304297 -58378 376586 181319 50408 138538 795508 244780 903106 287069 343507 287570 773088 572518 38487 397541 18771 80795 588370 269010";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l
```
### 500 numbers
```bash
arg="8375 21239 672153 -72057 453707 -58539 990626 306323 -48835 758377 884470 509810 112043 892656 77109 293906 521825 664060 732670 559720 37743 785827 227849 732003 52591 525687 -93777 932082 196888 77514 309997 966943 897574 864600 168767 -5289 831723 442722 546609 720770 206348 -6384 972266 -50107 686461 -23624 966803 713270 932002 617214 276832 294474 954009 -92011 217693 758423 621953 970558 740180 678357 954212 218402 -62206 242869 314408 -10340 6044 955549 485926 570319 309062 -80874 717804 481830 647945 273217 124285 225343 50232 715141 279368 192756 158273 866355 449176 190425 658964 240585 326814 919847 781695 298166 227903 915275 907849 815943 290830 396505 -42110 639709 336247 -15925 275415 397221 289150 245494 253917 505566 691467 36534 -52863 444177 -54316 -33508 509372 295639 87311 615794 853712 815207 855207 225760 856764 171709 581323 261025 127568 27339 542516 470333 934702 -89106 634172 189506 910063 81886 942635 316329 121914 127279 735522 253422 726586 702888 640432 800717 616006 865470 -99445 635001 619831 739107 -21357 522953 583475 -46750 494306 415126 -36441 80170 449433 305499 614937 27005 958023 -95704 246165 628914 177343 614846 731416 413801 855542 991056 968682 738810 351392 708121 122143 57762 568924 620206 816463 570885 536747 414756 -58911 846245 709458 370744 680529 343464 134007 934796 -77379 530327 627301 60518 332215 276658 934151 658981 -29442 708637 61476 49753 -74578 555792 625731 283975 328963 433010 855746 366995 340805 784998 436191 803153 390116 833193 908339 658715 43990 610035 876770 375390 770407 728250 832113 -16285 140371 466956 179946 498453 91306 620551 574556 446422 930915 957277 347932 266971 979600 567150 791033 482736 892588 433378 978925 125089 655269 553804 546636 438731 816038 159291 666101 719996 889280 939002 21118 82947 192021 402114 12898 848558 351919 870492 878729 454786 -63118 608117 986311 148364 561275 682586 143564 654556 123353 73949 947431 69729 179440 958861 908802 477524 64630 372277 866845 298101 482256 477979 670380 386338 749597 114372 -99897 842748 148178 339610 937200 389633 457253 129870 117019 792966 831687 378138 538834 131054 79882 388614 471407 -39970 877296 336541 431627 933449 618354 236375 714907 719696 995533 182460 206395 221820 967168 432859 -90326 116780 -69749 940940 67752 751959 743074 193484 59824 793718 843719 413643 -36772 34686 856487 438894 272383 899508 801534 953718 688285 338438 674754 631327 344851 166572 -18738 817345 792706 280497 -89627 628589 523299 315453 -54011 166513 879254 470852 567151 581259 56918 248016 938627 392856 34423 212604 836636 246367 481256 517391 900713 325301 -16621 955939 407498 898807 650073 613678 10406 403958 94462 -28120 727541 37909 -4536 536383 771617 782043 -87655 234074 547536 601761 926399 128998 273048 548642 591218 608720 434598 -18710 933777 -75679 588837 177034 633585 152487 -35268 778096 639602 751720 660678 68522 -25529 175632 430629 926015 284844 26745 165309 631877 775858 746770 838019 998326 687526 -78404 14990 313806 75544 1758 608417 689868 -33260 358240 417260 53818 459262 844533 188697 245181 163427 712184 413316 764183 777790 117735 97410 760122 726244 613588 679679 707762 10822 971603 832025 699519 333816 -52067 274113 525740 85583 905745 480799 -43251 593853 345589 977903 874837 694662 657554 622655 415793 649028 644915 818633 186028 39219 354089 2792 520563 718879 881737 599474 723519 78016 902758 643928 310216 619049 338139 831335 891103";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="586277 918288 327985 420153 281190 628899 771737 250534 801140 -12260 218952 972070 33648 909872 347435 -11817 973085 30271 222006 994091 -68485 556488 515098 -28788 590471 358117 230481 444790 47611 228646 451470 569941 -51357 7246 168684 441487 283534 707843 417866 70955 -55208 235802 555038 432813 748200 403156 431261 448330 451907 655370 406892 -10700 588784 644018 208179 593973 149454 328389 580726 176993 219337 350497 626775 778873 253993 121912 823655 -60851 540834 491027 386658 592125 36061 589995 148775 904820 -37025 144332 111874 709795 931188 676672 761210 409918 553171 646055 899565 -22892 845045 807012 905080 416605 578867 93472 893450 130762 165308 785787 105141 86869 502585 850388 -50459 8466 828193 968086 564246 631210 664467 98279 4857 47120 668412 143937 386343 723891 610206 981130 -51493 129812 836333 531207 23820 241744 259694 -65579 39911 972351 801726 -27368 124335 581501 157101 767241 860149 825180 67718 -91857 708608 458861 637056 617366 102449 82480 851045 -78666 263720 406418 690698 -72795 304658 925513 -56847 692551 203890 988490 54131 909633 283231 -64099 787685 888505 813173 955891 695049 378083 46281 462771 865533 291904 -79336 965757 848641 281920 627068 241127 -60963 122726 507421 553259 783455 9129 856345 505231 772736 151143 847128 484687 421399 632482 79179 -83721 -31116 148734 691178 287686 631508 -97689 824971 129012 357426 852390 955651 286154 906795 -74344 368100 755139 -80352 585224 183065 236520 591005 153493 758855 159841 579797 522350 787544 -82482 956365 952869 848041 460691 105417 339105 -50726 141043 199850 497461 422812 877431 245376 814647 817780 -77470 782804 607513 385120 668280 350748 338194 857300 963701 778572 352885 600800 629213 265322 1951 123372 223966 247845 92761 492965 720461 525887 115431 706421 905195 540422 320932 587510 134526 545161 675930 645963 201333 543814 -24422 154461 582204 75262 997061 604966 221933 881029 59137 69532 185211 488128 126280 649837 995356 28945 360827 48999 -64902 646203 479610 487140 299546 -84769 829057 659993 472297 974738 103717 56025 253034 259646 129691 224402 350424 317927 914561 201392 285250 549185 902511 687838 18194 822913 548520 942447 -3874 606448 258018 38988 118014 -17896 -87984 -4938 744336 914732 317444 849077 307440 10544 758548 204323 292461 749743 493152 959962 971756 747162 155938 53210 839652 818744 248491 517416 489466 595995 468740 900121 -89896 336592 512934 625724 861473 873609 91383 801125 441836 726622 631370 404712 683736 975970 41374 443163 743157 63482 112412 293856 35187 926915 147976 -24304 730028 506132 -19782 -82371 357479 214617 957054 -23469 97848 -20421 989864 -50777 416738 870331 974197 161264 19406 889032 606313 394761 794747 758455 283224 172309 36739 299098 193785 266115 463165 20304 359428 391883 72994 673091 867127 -66960 723224 836668 506565 847558 524174 888764 717476 996417 597467 639885 735458 393475 603205 584365 311838 216580 502904 996216 -20382 -2518 511416 516127 864696 930278 977173 48817 73809 362457 859388 148215 -75505 164464 597329 567895 542839 964652 527619 488766 434576 252058 342536 509847 243358 678930 395270 980826 804066 879427 858937 213883 842782 409969 504539 224347 -55832 756004 258053 393767 140231 982674 885179 808536 230148 54762 169244 -82904 506951 -50022 971806 291216 577168 872240 930245 609698 639002 -35638 135491 309234 957652 298429 265580 268414 879866 69930 98401 409568 394826 13806 144865 138544 879841 92504 239027";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="113314 108459 485917 228838 499666 102879 832583 395432 231038 215553 686163 -31455 215750 758851 450796 40560 562100 857171 454595 781300 763856 203984 540751 818825 10342 -25585 434965 994713 81452 868592 25252 19125 442238 88668 236573 710729 513564 16892 595659 -72113 255134 103218 63038 502203 442630 108999 591113 385854 901240 261878 548907 896202 399154 851312 433100 547074 558592 757165 593953 551532 669582 -40569 448098 944457 23251 154480 675417 669069 525904 546525 464775 200053 367037 192810 173263 959913 587537 913072 677963 123723 -47710 612465 304484 361038 106271 503085 437952 175239 259099 671707 926200 149071 254360 898016 167974 750366 909599 777032 827193 249761 628835 117628 468058 886159 585256 604007 -22981 161405 898865 -86664 511282 876114 982574 949382 -81508 -64381 517023 845023 142880 289458 941217 266908 28097 966397 183267 403437 40321 936135 611266 835006 200319 659448 635341 523218 886278 109353 886242 307052 544216 728442 646354 733700 179063 87740 480199 988635 260535 77822 945925 691341 276901 765417 484503 442936 340718 129278 892896 702349 205142 211736 727169 976845 828333 -16146 680662 641317 203289 594799 225716 445567 360926 688715 -5645 399219 572697 541812 410382 475420 160800 575766 241564 686539 526302 275531 -18549 896712 661879 626286 670280 108319 734691 247214 368192 57576 504157 400766 387941 982676 251571 584587 488157 924565 609565 429663 885818 -40670 491637 300570 149964 86220 881613 271233 489488 407744 529184 -86758 410040 510817 488718 -81177 74996 901887 933803 709116 846772 -85635 461307 795790 332039 -42767 565476 288737 37388 99987 585130 647333 381558 52546 959035 222103 845850 415665 44904 946684 762925 630191 762249 912551 245157 879306 -3727 244528 156021 741777 27435 122585 -20166 133570 112255 177963 860920 200585 86204 123464 716626 796620 566912 -45930 740051 613608 815632 854011 -11970 201678 394368 146855 37004 951054 453761 945138 201660 529671 335121 633687 403112 605442 576721 -56769 866845 577231 371748 -91866 611017 10663 484550 917553 374028 -70056 353146 499685 291753 182179 300051 -37492 745686 603012 114707 494899 85541 321183 808966 131118 984279 551848 235232 938978 22208 429479 706242 165185 244620 538638 889986 -86957 185895 474448 774465 808776 432208 -74882 363593 103015 602068 273641 233029 -87019 827824 231064 38424 955287 421084 712186 210487 754484 193020 336918 867066 -70503 955004 104065 127451 544191 721241 334819 913228 858705 -17731 225687 604131 296453 628321 520883 723903 877549 803019 339883 851581 16973 732386 -38216 537871 277204 418444 628872 304175 120903 220419 665666 155546 726875 444669 659634 296508 204198 451820 201267 177608 -58234 216029 693929 579190 370009 618018 8646 588967 249281 334534 375768 987748 -8099 3456 671663 627080 897276 929642 110952 838115 670912 702583 869667 480318 967540 843165 363207 374975 228636 316966 -66216 879532 -43862 789459 568465 978341 302607 -55640 49671 459517 442037 808103 385758 153528 191170 218248 423956 -56265 606654 314882 383572 281042 110453 239834 -21999 358544 30068 976672 192792 -61994 189142 26173 842752 833850 433804 409961 540335 763603 676778 129988 339996 25231 547883 29582 323347 -49619 145427 593404 561091 -12375 427155 949944 247493 45763 60732 175127 -39699 983716 369111 451291 771926 -57567 431960 359214 300384 93797 871901 433675 257771 423274 89075 72292 373452 604616 812579 480718 123965 324737 -18357 834379 461392 451345 578386";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="545500 -41264 -96806 954149 728571 -63989 206852 -2612 230900 -55780 354488 434323 480942 629668 366917 466883 292021 196984 227442 -26763 854384 152271 513052 88872 565472 375749 838618 345624 728724 466749 1135 924959 122328 906508 651986 871995 -41949 267577 243142 165582 975079 108314 534393 962755 256763 694821 367899 540161 360669 441849 152106 430848 552701 651135 -36263 75949 103647 971500 722388 175494 765807 218701 258937 704406 465464 611973 105965 664067 125868 519307 928181 122022 381351 167014 217385 143978 311556 764207 414483 188977 387824 204909 646566 781589 924541 811223 160127 162441 653320 860970 593960 847403 556345 54202 695397 -7845 181845 -10516 738563 549858 342627 978172 856175 -33064 185360 931456 618605 -67222 719564 649031 794344 694200 699464 802084 886482 569084 257990 574963 265010 100643 476259 184001 705578 376015 917360 -52545 387655 651279 87935 80532 7705 -50309 246169 219479 504816 -7900 133389 597788 900322 237019 274543 523733 587110 -64055 923468 171724 157761 121765 371790 153147 544794 647380 -41335 175655 211003 537492 362433 692551 991907 138691 -63187 -43253 325354 122436 80996 493353 228706 -97053 898566 707575 86723 807534 476775 655136 212376 5458 878860 703463 -66868 681744 761426 320458 -63279 540904 59189 883932 -13839 754028 337723 127109 513598 868813 676508 358844 988222 506293 842513 117571 694533 246795 785621 137476 941874 -80728 284607 764695 536928 313581 -19622 588144 379577 407590 872939 261099 236823 412081 795771 736574 213552 580435 47370 600050 234321 118956 39482 703917 748268 40205 129051 945433 765442 706537 977418 303555 800565 77494 866991 573729 836141 624920 964706 -49393 273915 627236 503331 648784 -73186 416498 607693 974347 944390 94395 771135 769295 23675 103859 837124 411580 309376 386654 132176 791585 40020 285968 19106 408749 811676 587424 584276 96570 -16001 52124 808896 739215 886651 873721 487860 741778 411094 848149 909743 550492 225537 782959 682042 537435 550076 71723 252238 953146 291005 360070 913665 166754 483274 722501 339770 850939 173042 728710 465176 -30220 280933 769574 785839 255373 818445 108003 714881 957630 795549 228125 575872 602458 643915 482622 -85787 440573 857337 854982 118118 307075 876759 469390 859034 40102 269452 330412 553451 794461 498633 332707 970368 537823 267464 113576 243317 878937 96807 591581 965495 419108 409222 627901 730839 707401 574860 422249 820130 350847 643160 60951 284658 993077 119208 -2694 442294 -65863 610564 -34433 845082 333595 197533 158772 486950 997375 39933 261428 695306 445605 -1715 20815 204786 51869 952943 191260 716423 -43818 88913 447179 190698 198373 500444 683639 937122 547980 642904 649077 342613 14465 982844 140609 534157 784405 699754 37026 6516 178401 -30483 -31594 111338 -17840 926864 301031 906372 42614 592249 273023 301691 494500 211426 476864 976226 540523 -75376 765750 52239 360269 606982 -90335 22535 554798 765459 812898 294976 18078 170835 464712 16825 802333 759172 861688 316568 874308 965065 555705 511709 486404 150191 999418 389095 921505 916900 492571 677288 792175 451870 152612 843664 681604 262864 572308 32219 169137 854253 86664 471007 899558 233644 737481 845668 857268 602949 876578 59226 516747 366708 -97258 719780 673251 914149 283844 955790 788023 261322 413220 724091 667142 644298 345650 735436 50778 937512 727137 194173 649383 656681 411057 45241 645053 -55966 703823 390108 769519 469474 377507 534685 307483 104235 749213";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="445166 -61091 57567 435122 594431 514079 -66777 541061 165978 699835 46028 628325 318646 400983 418481 879719 733093 846315 76746 451780 633029 15244 554796 585634 166210 930061 409193 695936 144974 -81449 188205 290341 513538 328645 386261 -24995 708222 894194 928127 492707 372241 390122 750368 784345 36548 379097 413539 841802 510901 527906 718031 597520 157131 736364 581274 475880 364109 726536 789884 315646 -41171 597009 746694 501154 613422 421304 715242 630321 104709 170892 371273 314333 -68732 731833 263285 635150 133848 745345 822689 267248 582733 626706 402968 972858 499881 993144 631352 884469 879157 920697 32078 587933 316387 450876 566195 706434 130633 515836 417458 684756 299943 355832 166840 -80237 738419 345078 396465 562862 906099 -58549 757972 -11067 684419 799550 148268 210511 347822 396967 805134 899151 421818 246862 -12093 713703 271234 883311 260602 259487 854809 100345 608221 417709 278199 212434 752795 107197 318245 413382 -74098 328439 374728 597873 258963 477558 392384 516934 415354 580372 43846 929337 950503 941731 856448 281826 953382 311689 190731 695340 373374 586406 560865 789841 395270 977250 566976 633413 800916 325014 -76045 27583 292403 385976 581548 807055 894142 634908 614628 575615 911379 183742 527265 579342 605418 296715 100389 69153 867172 155883 576990 -90173 967517 685522 970625 141000 927693 424427 416362 567193 456739 569811 -76197 200228 976344 602871 440548 2871 932631 763844 530330 656527 363714 734985 719121 114389 -72646 966494 610779 996683 976109 436031 200122 12791 601880 916689 570990 568568 749610 -71221 844145 -24176 605417 67652 734656 753497 608067 96897 -41820 191836 29526 649188 494619 591936 985366 -88232 19055 724435 370632 -12366 855400 396240 881631 903411 -11933 876745 926973 454722 415554 972549 271981 925021 817313 420616 870936 295679 737409 651448 -78595 936789 641762 952182 191472 406581 341650 509295 351093 257254 911465 944125 885732 168283 52404 -46040 79398 -69699 427810 441565 910888 37939 225529 120042 104790 673496 572881 116420 499854 968510 850367 789465 830516 -64910 281183 921086 194229 797630 14731 470386 311457 984244 441222 381946 153110 -3081 836706 329614 591374 715630 -6595 296881 423407 42202 491899 798930 516308 685878 92369 357583 -81176 320578 812627 611737 -76012 773056 -37575 928272 937195 52464 -32726 367596 932857 916593 -94924 769587 187083 512723 270979 963952 315522 -77828 314169 167959 -66365 601543 550736 134623 42205 783759 985278 199317 635547 163530 395248 832575 295826 38240 250341 224711 142050 326013 397329 89047 976772 138766 46909 516651 699180 577491 521669 992466 541105 109141 983641 535606 -48900 567458 109811 640950 341939 700957 647729 -29696 790260 918457 901582 104691 960142 473808 880494 735469 753448 601168 156899 9131 46488 722225 354424 821257 328434 973572 583349 780666 852105 -17501 579248 308026 235624 528541 347211 78993 241222 701456 850001 38471 875549 410227 154892 669454 590605 435103 694158 728254 96823 421633 628041 752741 175609 100323 727420 152157 -74829 766650 96494 547616 449235 -18233 74002 731323 795295 321485 -72387 896885 957776 254906 41274 311564 117804 189661 317796 45556 202126 -84121 756034 268711 858111 848492 407236 616639 979145 478731 539640 116549 855316 76301 500935 471243 307402 618349 23618 340735 722462 589468 665814 62137 515269 225582 386939 397448 970171 934220 622440 169920 776617 49476 484952 262201 316030 768829 182072 331584 408625 278297";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="-615 85115 251485 935936 468258 -1465 447600 236878 360840 581507 767978 800992 -57521 103130 -12492 715964 338201 968825 42494 864018 331965 455049 473568 63052 532409 979494 910877 49761 755883 240773 31177 -97774 -31444 553210 738101 80634 209827 348160 438351 454304 270324 16601 242509 -34374 587799 683207 620811 830133 464235 723762 840289 422878 206482 164082 515234 435294 420967 294954 607801 764849 877437 -37205 481868 223142 548472 -84174 347726 -91148 189185 727721 971796 -11455 42983 142415 239867 434554 163146 731082 172592 458143 260133 -54643 512056 766163 157628 933813 887855 598163 587190 66806 224790 849313 702025 913174 304152 466311 925049 539395 350450 -29789 773864 402228 -81072 898644 359050 792944 451907 602414 927613 -24206 304607 495604 927920 -48468 717801 255141 717271 879569 226259 851148 201281 242420 468385 762165 275363 620287 513116 928956 836063 401339 898656 137993 800838 476883 -94636 264249 351512 246532 36968 579572 533535 265333 357799 37753 127381 -68629 330103 464389 80516 241341 740335 681229 222821 182418 813602 515154 891248 709272 594207 395379 655948 242558 553978 16316 13834 657537 180213 236544 620711 868115 383908 97219 602222 970278 39574 744481 480180 749241 875567 859628 22999 457793 879499 239960 936867 316708 569204 29170 676838 -98618 267971 659454 110238 786322 358212 488234 69871 394931 209210 688819 285496 26578 563539 288686 536657 577025 585877 856931 543615 776520 538321 497446 845383 194247 82667 137629 202797 857107 905629 -16074 382088 851177 382730 294369 938623 470776 974459 308888 385176 782542 935609 365096 672672 863295 222959 42582 337967 585358 776708 10943 46255 197397 908055 576727 557486 -53622 159487 943203 574684 115987 310192 690868 252908 947615 623794 997564 804968 -53495 32621 542978 322494 504363 477837 93150 -46174 193911 569244 679532 314616 486931 697619 70380 180129 470644 53520 463412 77262 14926 245570 151302 208087 288863 977148 770556 -80345 154672 501190 749381 481174 888530 711532 991350 168089 987507 623977 84970 192468 117677 -77522 350806 861669 458021 399078 426161 144591 689698 468643 964238 444812 614661 431366 900744 788777 903590 741815 641931 994027 953016 -62987 109427 932170 296530 880631 53874 411714 46981 916520 819901 145763 809838 633943 610442 11091 381002 19861 486232 -82868 482309 361990 228345 -38116 666671 116344 804798 -88843 961379 954654 403818 46606 194522 22373 585112 113034 645990 232472 168589 289038 192848 533781 -36313 834148 295233 230709 438880 278901 932702 721672 612759 670570 778015 774286 217149 839127 741643 353378 187626 -67553 493115 67372 944683 259493 886325 904428 702002 616824 865845 891541 986225 39264 55665 723123 695976 221979 292242 446350 316789 384889 319220 307376 249554 212517 720077 515824 -42561 150835 126133 114381 167104 178358 439121 897370 631821 735533 741325 581569 621016 -87239 420622 635527 992330 80787 460916 99268 210599 73238 730788 770072 267689 347804 940335 706971 -86906 15350 974550 224401 719384 47938 130917 832741 624254 343992 332830 535077 -15950 631791 855225 20931 40057 774125 887199 737878 27193 844554 865665 39254 701708 726085 831271 397806 28675 959415 835549 443275 406442 290141 963134 28227 -65722 379227 579814 709600 545144 867352 201463 324 640301 511182 929916 12507 -25021 850800 365695 476983 197490 849413 493242 118726 320297 837012 619638 -40668 873436 659695 209696 927783 -70153 -77230 889273 907751 214003";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="667553 711096 272529 499460 221023 967867 283573 774735 475939 648276 673937 421783 120435 997305 48227 81971 633873 494556 857907 350242 828028 794752 789378 544367 984743 639819 150 587639 133716 256432 581577 104366 448555 85187 451942 534875 770937 -15931 163535 485804 91902 382844 295920 768328 351007 526423 311119 -99947 808304 923519 434668 917530 469413 328741 373203 125963 315617 5773 467992 -33417 978732 814275 95836 517409 518319 896723 505605 981871 900479 792321 767642 586128 439727 120091 969515 -62852 277781 -46694 824995 321551 364715 868910 473792 294912 229440 149548 244851 733578 411430 913224 519499 185314 427285 66047 44413 493308 750167 175105 387689 983932 70226 987015 583130 740609 697962 615170 52372 145077 -93530 845459 901576 321748 903991 -82215 339868 338982 271889 435748 938954 472049 314680 -35551 80710 162655 141195 421503 985260 171942 400664 715028 129659 665718 511481 14742 222892 239490 40154 387776 931487 352307 393728 14326 590332 596019 67341 784897 6936 120973 410254 497117 729274 -54873 115098 518866 589317 558030 941627 875308 736901 511685 727638 -42410 981763 909885 189152 256682 467743 152946 441409 137503 783830 223513 402177 532196 -17655 246390 897514 810108 881473 514978 860454 -64456 668767 848130 531603 803591 367717 371170 487397 61134 209934 851732 207712 150469 259311 191794 554400 493089 970903 472008 176589 970712 955195 594779 438021 697910 667680 331707 727303 767403 452797 36519 195600 415454 291675 509927 759475 506572 829781 121445 989572 269329 168904 264612 38538 297711 158555 347028 325115 455550 137259 678550 972144 147558 549153 757438 735238 16884 698830 499698 616818 833594 907305 853236 580339 924641 839849 731775 1835 50852 814271 454429 -68019 135129 319971 189818 209639 424773 959025 347047 254883 772781 376284 70928 593512 -70857 384961 87982 815292 899853 758381 905511 244615 -18075 445724 260326 -47397 399375 378279 977493 751625 741883 43022 897048 309931 652131 404600 935528 60341 355698 233134 242719 -1759 -31435 35909 686769 927608 579517 597573 976028 227473 865815 595290 472708 286625 593659 826921 320798 807463 75209 52802 83320 822981 400932 302772 -26890 626882 -51179 175009 306286 902877 836107 257741 177572 -6324 -84657 641027 393486 429361 672711 809626 -47903 999879 757140 702683 549003 828993 396835 535203 184746 77468 594606 532426 978369 786301 322967 231789 503550 602642 409023 793953 484748 246301 752722 77540 308632 558999 347899 798699 970936 193192 21263 705135 379343 816336 311916 749400 -66551 513520 490085 161074 382982 926277 228925 387592 461476 -71459 912937 867262 174973 406964 388223 748021 644064 702599 200958 311000 651326 467399 -6554 633097 874803 787832 42020 175514 859728 -75116 88919 976091 542503 415171 329235 5612 428049 908916 189381 273833 486742 146918 470809 849349 892562 865588 35085 145713 856971 -44492 468383 751603 694244 885854 8871 675609 325845 817679 594190 191016 732811 508641 744055 209104 593736 428728 330359 604411 490270 814826 186635 539271 -70441 59996 86684 667779 612620 329674 678688 -34428 833272 689871 107747 986395 795769 284564 464445 130589 65771 -94307 50657 -43904 578670 824452 -26411 649573 755067 659806 599589 464424 918013 974030 94273 811372 518245 747646 6640 252707 132079 105766 702069 854872 575481 552089 -79941 894032 67328 542563 525943 290214 381083 957156 576797 342535 304279 448588 97506 157371 89336 714870 -85438 640716 366118";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="712440 733687 307400 45932 -72512 847813 454684 262379 434587 243158 -56992 528187 37415 516684 442456 168272 -5511 936305 -98498 534075 167383 162810 672668 767749 799470 -14729 321392 938494 11593 381906 538140 377998 58085 233197 216326 906803 -14175 701017 360598 3238 789 857376 701049 374066 956629 309854 413157 9202 444947 13573 471413 181609 78781 21568 917266 709581 363485 718168 981831 338718 73658 476831 937291 404513 396904 821533 92013 828926 9622 208729 910214 886944 387043 154963 343267 431178 192592 422641 653458 213340 303678 318580 856601 571226 966926 863341 718922 814575 890420 802130 947636 615582 27434 283403 506122 425286 173979 873890 754509 837969 846601 550267 747718 230052 335020 -19648 871658 735653 352575 923290 355193 619021 508000 975362 595963 394397 253019 799540 664925 904830 211954 897264 889344 -20830 393993 262805 907578 493199 26430 259875 147485 948413 527049 809464 221989 655123 818601 244620 -52420 515717 584053 734695 533764 686794 46475 -26353 251559 590864 411654 709866 279340 64029 -72791 646779 224754 681137 -96675 322559 562733 980192 534299 548381 674638 963358 750983 637953 937509 373261 874360 957727 479501 743200 431379 274621 575053 987830 173662 389930 825204 102237 -70553 115663 289353 919469 -57036 166221 796121 260072 610666 862398 -12487 183821 687017 360159 471401 117685 457305 537873 101592 256774 942398 286800 93939 954299 416615 537293 66382 394583 847658 98620 635023 412290 454811 82740 517357 -17682 73890 32436 469599 390953 301684 283918 764958 366379 -81331 920610 77710 547214 110594 -96643 311980 703172 536528 73762 969368 499471 -42620 683252 49956 496847 -8001 725182 894394 991684 785169 927519 167296 946420 965284 322147 935187 922403 431114 461753 129048 56706 419493 920404 645695 444326 362996 896812 873757 54685 979384 439348 506348 211447 537353 484690 727392 -89112 497291 853187 570043 288645 48341 257963 483823 691212 651720 430557 741168 84012 860497 -83330 627084 841533 108103 628592 297121 808631 46708 348407 966854 495619 454776 -55260 66663 588314 898433 538718 741338 267735 310919 805451 602024 978835 195115 106864 94440 407388 472447 499411 214315 260049 686262 214089 63940 56880 143883 808536 658301 455058 744065 110688 75397 473842 212648 716776 792704 343494 935192 577444 915375 723961 251799 601093 660106 436163 387253 880233 196837 144145 -56497 909706 613283 34102 643970 588822 522465 441887 208082 589545 977324 264045 144083 502695 622346 350906 613389 612610 866599 714429 -61500 616492 965889 944933 600070 552358 993475 408867 263309 582956 666253 56769 -39451 149232 448116 -58599 112739 388349 682803 257794 185695 610093 -87369 572403 718260 18353 445510 163893 231069 1504 560934 71783 972461 580456 209993 982698 548133 60657 -54797 574646 940142 33622 886510 592498 931112 202348 -95086 806984 22714 354872 221658 676730 -92840 773409 105010 381214 805506 399543 254554 493945 -28630 437504 150428 684172 559487 929866 302996 969537 503693 771441 628966 169703 426551 387725 950666 751511 865676 338615 760069 895718 151425 258138 -66954 748751 -59980 368396 367255 757079 160210 889839 750047 78164 -32184 -69667 76972 376275 565824 627396 280753 344498 697666 664027 623845 827854 723224 814636 999634 308582 117076 112371 365277 984290 548561 852861 521075 68783 525210 307984 779168 383996 978994 179705 252860 434113 457481 609314 489476 613538 220703 745794 495739 689164 852622 -62573 777277 619124";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="70234 836609 143459 68172 200405 -22158 967332 340595 758803 805928 856117 913719 182015 902643 -28895 -33350 -47892 682543 708258 760458 400809 672904 -40820 770548 797755 728478 519606 674953 -15566 185617 676950 504231 -5470 53662 468004 414139 466366 536850 559365 842515 191709 800429 810171 -7154 570862 -46824 405283 -73340 145907 785795 989624 305369 991081 869107 810114 537545 331290 434598 301765 357617 928551 489269 815424 343879 761982 642305 -43994 2578 805255 815915 -26417 552789 -68518 651557 69273 471213 467217 196552 579137 549337 628691 798044 181156 219731 336403 888849 916757 801105 547662 457600 646258 44211 -18989 232372 584968 903884 307516 547713 312497 923727 900732 291444 333934 771701 538132 287207 574860 325492 506354 265463 616454 155185 764075 528927 32751 97182 851701 392010 681376 919097 283930 239663 218639 608242 138541 531713 -66397 989156 912669 410244 46668 75309 684616 516972 660379 48734 899795 180563 238856 296191 507864 728054 388242 554143 686425 466737 349526 591575 825320 71664 396338 887301 634637 500464 724917 274631 874349 727667 762784 374759 60275 325289 594304 927974 954972 630656 644280 466365 47743 -94540 617722 220894 898487 976210 335550 114012 23569 250131 310458 838613 739342 980873 892307 297475 722740 90395 245969 860887 444304 308235 67954 438996 381317 755692 804103 -29185 950359 664125 575961 543148 501556 768758 407864 338667 252459 627078 303897 4706 254128 836230 460521 284616 160484 384892 563717 -99805 606892 -88879 67147 161564 7783 672203 165388 914180 916098 858054 859864 614044 -93652 404281 401029 67339 162396 147101 75689 402808 445471 683671 388576 336798 56365 725139 164094 249237 367125 937216 -57227 112699 693327 19739 301203 426061 387255 869216 474986 418291 588184 762852 111515 599338 1036 544304 601043 628406 324126 1113 604265 122153 -93193 153796 629315 -87599 955928 612944 513798 958168 224303 322009 654467 624513 539528 920858 678877 493886 251518 920633 880053 274630 -73514 -94916 400109 252197 359097 214326 127055 68409 585208 257430 514302 226010 474850 -77396 331804 824643 76347 728868 371345 300190 978008 149914 259752 856402 277484 776169 722614 603287 377134 779980 288044 362029 -4308 864430 -63624 442235 924610 509132 723408 646394 -77757 195322 116751 -68422 822971 605117 710752 197294 944830 374290 146154 -78455 923671 687958 327413 679024 903694 248964 302306 161904 596555 893535 95186 45481 570506 154997 338364 35340 771398 807189 -20411 33977 115689 761856 657759 641732 415148 215746 16786 539934 650557 -71209 52511 169695 99667 602170 519359 239157 475619 728346 755784 323081 187251 437514 372361 108737 92984 493538 209835 98561 200395 943895 167002 245468 210469 717194 314708 478646 119164 39134 689838 108371 -16424 708948 98273 322344 842908 303666 382319 9198 903294 429487 447551 194945 203309 -9970 415724 930017 182693 181574 -85211 381011 164906 520078 413584 535619 677120 970938 85836 422864 758721 737545 -83533 355351 529864 490166 401768 629222 108014 891777 556020 514167 185895 246088 880158 870693 280157 489322 653768 223789 718456 226078 801769 267858 376471 936170 226257 3446 869770 229198 -59968 623587 244515 586670 832708 743975 21757 125803 44689 581706 -83017 413984 507755 865539 760173 719884 719116 237013 8453 747044 721183 164882 914118 643980 468809 878138 146817 957397 416242 872424 785564 986099 -40626 399488 862044 -23258 739379 56077 818804 761263 378294 909517";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="-21425 936782 599275 836734 303791 915797 568288 451987 733655 869963 -85773 966634 410667 809444 606156 645538 -88820 52038 -46909 376289 505458 481200 538230 469043 -77291 -84286 298241 322922 354926 841494 774449 990975 28629 784275 -54912 -40883 143877 -26483 812752 500178 313912 656988 868871 957633 445920 309471 931739 968550 15175 857603 262511 786113 607543 -74456 307245 627079 450225 715743 785366 285296 997997 896534 172176 186318 -92033 832633 960960 816934 300066 551103 816389 42173 2510 728883 792086 704675 525556 155273 209591 744853 469765 -40364 577752 74649 422974 421535 604620 887578 143416 4220 53231 814787 517186 -14699 601335 317372 -87835 747128 671594 984435 32674 -35135 515545 819787 728556 744383 185412 349193 -5506 385591 -22279 660853 35188 609703 35302 871630 85777 681073 888642 268021 838374 759344 842306 476927 739654 288132 86070 836775 8574 663738 918593 115160 205751 131497 56959 196675 246738 440980 892905 140030 265295 265020 987420 795668 244794 969498 505183 398166 895187 484477 59990 821897 246579 584570 27248 915857 153588 201444 884541 568109 384532 177352 765621 6212 847218 226802 440214 585665 154070 104579 189974 396453 345835 782681 380249 141208 332818 435081 942252 972698 844798 836196 614767 442886 977591 706541 846415 737602 503792 651996 311081 820114 339072 694912 897664 665639 305296 520008 806884 857003 413236 454040 316136 -20762 178031 346859 -79727 433317 309489 945553 630329 -84020 521359 367302 57499 279318 953617 315031 107862 685846 653520 -75812 538511 576284 986980 897542 670509 125955 655846 196891 -26560 838630 672221 902204 350117 801202 346190 926028 632088 672112 978459 701052 342677 650510 383158 974800 -95050 743533 633095 57893 846240 500898 806939 805423 207787 240624 602965 -69849 692502 520357 540248 75955 138261 827622 721937 -74057 619495 674018 814856 643835 540893 481334 253673 893215 394169 863125 -91122 320153 368188 507028 75692 546698 779706 664262 556256 541317 901971 -66702 468915 672891 309062 192950 983847 365929 296396 23618 679263 997398 250818 154703 756361 304754 546505 618624 882490 846135 640837 -62781 598616 508733 250766 429997 599539 511905 54881 631560 721956 56665 68293 206131 864166 427674 939665 273969 -51174 346367 969257 603483 48316 876273 908250 622272 778119 723035 675371 932059 65892 700970 14341 349702 488769 509306 7392 163568 903676 18756 67619 528515 260530 699318 983866 355309 292067 62446 898776 971775 229534 941859 833468 76191 802934 331978 659580 247216 779314 717189 567090 197314 910102 152591 -25492 509835 364378 69095 901767 913801 759306 927856 867203 658570 719448 218157 439712 981946 923406 576439 425604 921404 -79790 312649 807085 360037 -42475 1960 979088 349428 295865 749033 249686 167075 468629 -21397 718864 -44989 574634 303442 421075 109033 966154 824730 772568 951891 351269 834765 78914 860576 637610 46109 48246 -77674 987824 853922 -57103 98884 355582 63775 640931 493912 350536 384696 852765 540683 258584 -37559 243835 498426 479470 269325 978644 274901 72358 -61564 198240 437835 95118 346569 342833 419495 29961 983312 466149 370007 741283 885400 -29475 696450 792678 -34801 329484 805752 627593 768107 795792 447368 988215 174591 709790 244454 405349 861929 -58095 508037 34821 -86052 83174 984696 454518 -12300 859529 731848 161105 589156 357930 806485 395564 436117 326813 680779 648068 818121 879380 917425 211159 814191 550350 399394 450934 124593 641856 785215";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="846834 93980 758129 340670 884073 74397 398873 -69224 805253 77712 -48964 289352 5381 527949 587111 -5295 268209 500116 970242 614041 100724 713232 222396 372904 -36031 546167 197791 774264 187131 48232 -70248 51806 -93907 411979 855013 70553 397822 50821 436188 568116 899748 32048 385756 844703 320371 357849 743071 618744 900226 725362 13339 432165 443431 137993 -62958 86830 353493 400734 796448 771321 595502 -36340 359793 928785 832537 584701 270617 839552 415448 723353 170210 336383 820169 820095 491494 719312 785946 -3171 25976 760264 740483 162205 633298 751461 274066 691717 911434 308910 881664 903514 -92902 816923 -49127 287063 711504 149333 283384 134103 217400 606517 87034 584408 131549 384659 542083 891688 -90130 468107 886335 978639 408176 407116 499150 490468 993903 127845 289916 3377 519344 888911 894782 170415 586076 645267 908742 188902 906708 565285 691130 456246 110129 360026 186473 438263 102264 51987 580350 572017 781323 230464 166272 526205 317284 253270 -38034 275788 986725 979449 580511 569279 560813 684965 448479 982911 -49874 166365 222705 460974 56932 899382 100282 228411 787511 405039 659546 357115 29269 -99679 663681 829986 605882 58558 900237 -54417 11165 192829 250772 144477 47355 847892 674073 88942 655320 733242 -10954 702180 381743 373380 183096 260698 440387 378396 330134 67178 45777 873507 961542 986750 842282 860620 557451 504136 218208 677838 795968 418839 646899 400309 538894 20186 496446 478216 507613 989143 223941 470019 59378 876730 -59510 762219 595566 81838 161210 356060 -83783 858233 66108 676106 917287 247534 884935 464938 675798 871686 404507 576099 576337 700239 429194 89166 669173 953892 532549 166704 149701 709295 291933 769704 284001 245810 228382 661679 634781 973768 814846 780097 289816 989173 690264 367785 682874 674626 217120 751554 640942 258900 131265 784451 310863 906042 602061 426024 476481 665005 -96650 -57112 264261 271059 189535 30875 586448 473826 735456 594128 290261 695947 171606 428824 604025 -30483 246452 394056 173367 988777 267504 -67547 391519 440763 465316 404268 425056 255143 -22778 476123 597478 624526 947346 29156 422582 -4131 180437 561652 526276 959495 954484 249000 255521 226190 272136 823698 2766 767193 156840 496454 -60374 389525 486593 868162 390604 674086 464449 113271 629469 730983 58 342817 -54949 682892 397560 611609 438032 799369 484741 204117 -87640 424682 356170 -12288 497941 301140 762009 464954 921005 941809 196979 -5665 94330 562691 322176 28312 191086 440365 278025 229377 -22906 237103 517973 1968 398591 992930 844507 347333 508900 -19325 874885 32924 821791 117624 905373 20735 -37033 -71397 906248 255047 579962 215694 -23428 334468 375735 -56730 136683 536336 875247 -85928 540291 511841 431462 590835 915176 -70121 356142 814821 51108 163259 40843 -81571 487155 184135 387305 240843 631818 416301 870532 144834 -21784 892042 36680 166243 265447 306024 115010 824217 745747 213268 215851 381042 671017 22988 533130 266577 -34109 891839 617163 761922 761532 -75198 -33310 322023 475596 405254 710569 -28359 88128 247882 566780 642335 658944 220911 410728 71600 876928 -22356 170318 184789 419632 967185 569504 341042 544988 81397 763185 794719 677772 491775 594374 395310 644523 706246 720940 -14500 270839 696301 370291 319662 508529 420111 701902 312894 983026 237791 399422 714809 123511 986477 131274 202041 254765 152636 221530 730404 814533 -61995 112790 617140 443780 51012 339276 912101 901530 84814";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="136225 990371 667793 47582 901161 360503 697149 648110 109442 735185 373630 434633 -35009 43077 409265 771731 353756 197134 -58192 918224 711337 91957 829987 961715 498179 -94040 708494 664081 330989 504150 421072 791540 867675 402761 55522 495008 45421 237620 159890 989298 98954 220264 419187 466612 601818 867507 885347 -64639 918318 612077 260878 462943 468153 872498 750449 943634 720468 343981 774524 51252 637038 109667 460501 974897 67713 305290 319557 375397 37698 756248 221901 795258 -2649 953052 816492 18663 -36925 40348 488080 65415 383983 853256 -90342 606111 79924 481134 311022 24312 510346 722480 928412 564956 770181 826143 -34312 140365 442073 654884 163976 560710 -78458 23476 312353 454756 544945 235614 92548 367665 580936 669577 431906 725618 582255 41075 392522 944318 625774 147369 459965 190537 589914 514815 532209 630179 774333 990491 5855 703048 776434 907318 117364 293319 -95421 930315 118280 533104 885950 406206 -55746 779155 464888 295345 -44118 227804 695105 611140 914392 348083 746882 776362 291518 317080 -6410 89228 -72120 422132 51564 70104 117184 25546 355537 772428 548968 -32605 189227 -24639 972319 563466 708989 868373 977146 831006 30711 336446 644864 110797 349990 672321 552180 392974 281300 621830 966174 -40681 37939 215180 338536 549735 -78768 717069 528958 27676 986188 588423 160161 614975 54853 979841 965021 -78394 179462 996186 534345 344238 730511 315112 -60029 943088 260698 472430 826481 615965 451982 198048 626818 -82321 -12632 708432 23741 -49991 527106 557418 615066 373431 80935 849564 -85536 218691 778788 531219 -41247 144388 117213 5166 310349 910353 113197 21897 574977 389515 186157 773787 264440 11894 53294 550335 857385 266539 223718 -99651 873448 749793 771017 -86034 -92090 61496 193862 847236 937602 725315 443290 524643 70798 446765 720223 247916 195098 924798 663445 940938 -38114 51365 152752 756488 449242 -43890 288864 104072 304716 476671 71230 665185 -52760 466704 977988 428557 275955 972737 81179 481778 -14715 960722 204145 778062 541043 -16513 -38380 709457 632826 774337 364544 40259 404585 165889 937980 815110 243049 203576 81974 684753 221595 517752 513062 805439 369099 123209 610099 -70349 238775 702707 655885 601516 408847 22565 -89582 424855 1617 50946 -5389 78134 93477 350099 396776 434048 -52386 135704 760186 876089 809242 791184 283087 122032 875155 539528 551399 407802 489199 -39512 257804 889509 674681 307982 934494 310108 436748 738257 948615 430087 382176 766456 371472 -74921 620846 -35560 149097 45510 814969 287817 983861 668598 747072 306731 795421 280479 571443 379500 136319 304524 413931 491024 860378 466887 242462 408171 471648 97757 269091 711476 695824 -88749 -32400 987095 590983 151689 240526 708428 879810 241479 290931 3743 405116 401491 28301 779691 653378 457207 983643 727117 828558 689409 78720 -71613 248722 -78725 369150 -31283 515954 828453 110293 378089 320536 254173 448639 127888 998526 275663 271904 250138 855253 170164 572424 684062 124088 799894 89431 301605 658763 90414 433723 783333 523525 534509 184402 592450 121962 586218 927140 870123 50473 40120 562814 59953 -32873 603536 19574 749342 380301 107863 664220 921788 634821 800702 -24043 559305 965301 653026 959651 282999 665802 980389 632907 778160 443119 -50346 946692 -29282 725600 494301 862654 136090 809980 185344 655175 461730 -67648 680191 504456 636143 430631 10556 653924 606562 280385 504249 485705 701623 106728 859423 582410 652032";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="389502 231962 96804 -53216 851905 56243 876716 807193 671254 -61424 616693 106391 -91912 476568 69926 145948 244755 345396 417368 536619 742738 704898 13204 941227 55974 298390 309591 82152 885196 -70500 319256 824003 349917 932912 612562 7174 62123 108718 197630 766739 855544 633900 633866 948479 -33611 569793 566290 856388 -28571 -87682 162422 12719 137984 535968 92114 905337 335222 162654 309397 671605 449174 385244 184138 150711 -2354 333331 957232 -2829 -7969 476100 683373 899311 318995 285700 907304 448375 480778 304760 13676 82371 820430 408575 707329 583893 137943 879236 266937 933567 938783 46011 687195 872668 353703 734 151948 301495 29969 343270 740267 168638 457042 -16775 166437 173506 712376 961439 908673 234049 124220 696756 120993 999273 634393 853622 309366 781247 924996 93026 583332 600604 649714 64880 27461 -70862 162840 863649 284912 381426 926352 589705 823876 28325 691538 279710 55008 756573 878062 954655 44592 599714 108497 143228 417457 499127 402830 878852 837039 791555 56387 358016 98719 130561 834873 889556 477788 136629 998156 433859 8952 635310 976878 612013 248728 79982 538362 882823 509857 307234 299131 234621 127043 601639 188173 852590 860971 832916 651470 667045 514843 605352 542192 839984 724344 457417 553489 613216 736466 58569 708280 295677 739097 609832 703180 134870 764050 191657 -53088 286725 207738 87403 654281 130254 662778 423142 4440 639393 274692 453810 659538 965619 727205 314615 52484 87313 254716 950257 832568 -17924 829321 546224 582369 100537 927456 822917 205450 181991 464777 354971 655028 -23652 311333 -86885 373230 764128 504801 776982 603781 4044 82438 52670 866962 955456 470678 640773 148501 386344 57788 706426 656439 797369 54258 -87061 698120 874541 816693 759267 716389 767949 660605 672365 829419 526662 334732 204540 842073 540502 234478 491314 589716 889374 699294 666781 20774 -9835 11460 123258 716380 167522 777113 234357 59096 723112 170231 412647 -86652 -96789 271159 -63151 360081 742818 -35063 350218 808604 808046 245337 115473 777296 919875 146414 380904 386256 529621 586308 30810 698478 821876 155001 499653 42314 -77793 -5207 546875 945455 390450 10753 914026 542536 -21293 -73507 299092 107869 234533 34106 644899 -23510 47475 -9566 835451 317620 409514 35772 582843 95659 687788 382952 820102 17569 208098 911746 364942 842389 575906 967941 761384 521348 353682 402184 633426 181780 345516 708262 372419 22571 193453 298490 114096 785086 498835 430609 557386 945062 -32700 424914 654766 -60738 798187 715139 445472 801865 44662 311755 216275 511494 354162 -55347 793226 233057 111928 258726 -49220 580247 549213 991184 554276 987006 -68727 953392 835359 154133 961647 19073 796193 167704 702188 251956 -82008 390128 680835 332277 221874 151989 809035 -74831 132527 427223 300467 125936 754841 93748 194836 64716 179169 639238 608401 942343 3955 881395 574549 566956 21632 408371 664126 223027 152392 383556 640171 285415 471301 131566 121124 340757 25064 920902 343623 93950 95526 184495 945485 738244 136372 996122 -30237 370854 105520 830578 609891 979706 -87312 527627 55586 850938 -28713 947162 538241 10134 843883 960829 559888 956269 913401 545940 -64514 7947 277445 260967 110383 458909 387749 423893 83514 771669 479519 624364 109908 936696 620562 714151 974042 -56552 348081 849132 946089 -25913 419651 272320 -76509 847669 974286 574100 351208 651197 322882 345534 519042 203482 85857 252463 397182 -30437 195323";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="383896 872732 -80460 706813 393739 448975 4172 107496 56617 824626 -43068 519927 93172 597864 103766 407459 257616 480604 -63963 583718 827766 898626 626689 25314 548444 207020 433794 560398 525163 446993 63118 -48071 532132 727276 943244 93673 141661 -34238 386326 952613 936498 222033 168869 451389 629375 888857 799345 119764 62511 -35184 592332 462018 -25648 285481 153189 967144 671326 747046 610318 616193 704773 328892 264527 161883 713352 766008 -36929 -8943 888078 399364 56658 694214 229214 562632 314940 94912 404280 727748 762539 726861 -66106 409882 686414 987230 641716 588423 675687 606498 580224 254607 456443 203320 765150 682053 586015 -81231 62829 656602 456341 105360 802412 116148 533225 284680 239560 86662 948489 309881 -98070 19294 212950 979212 472745 979481 774146 748984 727815 148366 291832 909153 447134 928086 -56077 567135 802252 90967 59939 726711 829926 288439 402267 429198 870976 -26749 875605 135505 504378 637462 903316 158585 955895 903016 328888 86686 813553 563003 171669 333022 798466 819516 798067 770164 742409 280498 260412 -48106 355415 587638 799656 834785 990013 438080 355504 187267 685413 825435 -27470 459086 284201 -92629 552697 370155 853405 853886 934199 147671 580229 671092 581679 -53144 133839 476218 843562 412266 476693 52825 377294 -68684 836003 947001 473379 558378 924059 644430 901004 -89787 484413 655576 923682 286450 198663 475207 227062 467546 625917 554645 406816 -71466 448784 914556 806965 994190 264758 610509 725765 138511 713681 496841 529320 434456 891000 388474 439253 744055 313262 299027 532732 384406 251466 549978 998458 226099 184183 903648 325997 636139 506215 830942 959393 -93961 303565 788861 447788 437724 892223 194923 862375 459026 100789 116916 691134 871257 404276 -56509 -88532 310907 -73201 -45553 611640 607700 -46507 899872 -7144 950052 60530 483735 602288 132716 905669 -40280 -57887 296117 -74623 204956 867713 856789 848539 571148 74961 950137 826339 514113 794663 773300 252968 746810 119182 409960 638206 962633 135633 53646 634808 636390 327407 605181 768775 934576 657622 70361 296438 486403 -91409 532824 710944 387686 881142 676372 338975 236379 315713 895923 965768 376229 788035 224709 964508 345863 333028 986850 465725 946467 681741 287433 189626 651313 33919 461903 522940 407574 128776 372024 843161 725920 381821 332630 601097 461911 503444 419453 371922 201959 829187 199311 4256 651660 321930 224903 662257 885315 816623 626179 790015 689283 352607 437686 563454 5034 865231 930283 -27982 163564 441474 642602 322428 178297 305194 452754 806729 583553 462029 76600 934233 294791 233176 611434 450105 449812 522296 934353 -53549 342267 662561 -90181 177555 72032 72631 217347 26355 300754 688356 561017 712997 624143 626701 -82510 399400 610701 692162 152794 -57434 88434 506607 676246 635461 904661 644825 768168 906107 85318 718709 922250 825926 218283 51226 662612 332570 107523 982987 309625 526147 47699 819494 -96156 -92516 874083 494657 559886 138912 738991 284010 984064 600769 -23997 874358 285752 394202 -39333 400852 644277 919682 291652 242113 299836 512444 558546 597379 256137 754469 540646 466355 534768 18391 468328 729483 131936 931023 931649 716571 513214 56555 716513 796672 732243 652323 6432 652040 -59958 790001 137395 994195 458022 935816 414653 662879 301995 39650 702203 150944 643377 742290 959486 756910 87111 510430 436583 323594 189633 464969 585354 99606 897643 564676 -65222 879950 196468 488778 -44792 843449 608579";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="4868 -34337 842675 723071 -84865 285492 564607 779760 186968 879146 593538 592304 451472 846769 890625 234693 -44057 483712 888787 -88656 180832 435817 459608 299664 216611 512018 535014 897644 959088 507689 583611 -62903 568997 793722 977596 865329 415385 422059 914816 147041 470894 227672 723697 471688 597373 146949 201327 416584 745794 607758 304667 489996 196184 501371 538403 613507 498268 566280 928322 -85309 995244 48840 561188 30832 80871 135143 132034 544250 18528 379619 520478 81535 350684 98368 921307 844375 759554 256226 286202 503092 819666 644251 46877 517064 789088 723719 151490 -53622 604316 560898 647587 442420 371740 516645 185269 194925 623913 -46259 492835 306169 727028 -25975 829236 843359 236483 630748 568806 215910 37628 629560 720803 220290 298041 2479 805252 289636 718380 -48514 666692 180445 334918 593390 99981 -34853 764283 649022 2387 915866 578941 -24274 868121 142800 227225 396953 309415 -58620 758038 990995 153464 116897 585813 725154 950651 -38713 956617 319187 -66485 390452 102168 757595 13243 954010 518888 738980 652056 840833 242652 291049 266759 907665 38049 566140 -66120 -29095 827026 -25031 725399 614422 553972 926251 503464 -85239 402788 679977 230546 978365 214039 286068 116270 293157 429004 387604 773884 533967 797276 54043 668233 770732 496833 32608 626613 882039 94318 759649 699225 452790 306190 625102 948450 577693 115766 978546 866444 476539 961366 -7296 266446 969437 757553 158457 86416 129999 410863 901374 68921 123893 -49757 727915 141147 775777 338910 -22817 603544 206459 144524 349114 457133 629735 239687 401693 254244 265939 299698 160463 629311 392820 982386 24845 860579 455818 3471 490538 392306 262901 761140 41147 -47397 597967 10296 240059 248823 414569 13552 446082 55275 980703 643133 422143 367636 -37387 885199 993735 461300 878438 847233 321647 663009 763743 510050 714987 -20389 820753 994012 732286 -2696 333574 838247 64263 756725 -94596 524190 -7379 95338 260302 -53728 473391 534068 312088 562075 -1729 644635 626545 40481 836727 360319 756071 277016 739626 932886 376446 701540 85396 -4780 445005 317567 456857 654124 197920 640885 281446 210129 327567 434719 -44323 623142 221653 903147 996689 489960 888939 754141 377460 -94883 424882 554162 188746 678727 929730 873616 162331 484425 -2786 623090 -8906 702756 137828 511722 138368 120589 107241 995753 597972 443844 879310 210162 -80434 39892 491354 77547 574850 972041 160550 -9667 206699 393274 534198 240155 499016 255279 961826 -93768 415737 775911 916124 687674 865307 269619 862473 723146 808812 627826 883559 925860 905681 228932 -32138 233265 369015 619247 270540 101637 403924 -76670 739384 83511 224958 883249 -51345 472188 18091 659552 364960 463022 704741 924926 527499 591966 727170 24299 593553 746697 587719 715863 72862 482514 274025 47022 162435 499699 852206 25956 711116 95682 44379 730915 247636 346821 415829 554842 631808 -96314 -52910 438918 739572 114592 551106 736656 944829 66675 287666 -73438 921812 621574 415861 190242 929098 -76977 53714 460149 824688 226995 51203 672041 575225 197869 998640 17609 -35222 527110 120300 130884 589329 639715 502706 342656 33195 579135 829624 584567 674076 185531 732337 906280 223559 984812 466064 404420 992535 160303 424541 81763 244398 -47921 373363 147245 873250 588398 633229 548941 825400 872312 656586 187697 5575 909472 252226 589845 18607 106300 478470 104732 335661 -58126 963396 504953 297287 820887 264207 517515 34959";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="249520 605621 521242 53936 936089 296060 790661 964971 -20366 503251 728371 901863 189306 898248 312182 567250 233251 464180 108435 25362 306782 642162 -29156 337157 808272 93608 749832 976959 636221 214504 -92920 581805 973543 37436 537059 433437 365735 459170 149720 971220 840595 782567 421841 362878 805369 75527 67549 510804 785038 590748 874229 693266 591859 159218 908539 481603 954380 -49612 285018 593403 785106 87137 195670 387141 591398 279 342271 324361 512070 -3877 797598 792428 711470 -79383 10522 268756 314587 854499 449542 827895 964762 794173 550703 888619 586901 327628 976711 849100 189120 270658 939544 703193 435989 203246 -63524 593313 124340 655092 940730 833013 900427 364824 815127 328383 398040 -69017 735851 83043 38396 219267 391675 21146 746223 -7242 476434 960492 283755 722119 499772 83474 574009 869241 467260 139601 -53986 -54550 759365 700646 282699 51564 671094 716775 482668 646452 797602 947796 373645 419829 979664 414937 -90047 268628 -86326 933164 38258 239332 821384 582444 896141 -61008 226411 702889 533100 826654 451308 240921 20888 297742 436761 -46757 -77423 119639 271828 159191 -4923 774072 6817 620802 249197 977812 829610 292163 390895 271413 -69125 659018 579548 279625 83993 725102 98156 817630 279941 113422 432250 26912 506489 337292 775479 796384 847307 374937 745276 249502 -59979 21604 946323 485568 674744 825357 186607 279639 593522 540758 383232 504641 657132 628252 470491 501965 895756 868109 211261 244343 652162 510376 555194 116161 903360 487695 965252 95110 200117 969413 502564 52896 -33027 896668 795571 638943 322756 226612 508957 295456 255807 992901 756139 887542 941786 585283 54987 -16213 417568 654066 -60871 617944 966661 949374 871099 342826 348338 -94435 -78755 340162 980320 98551 -19000 685521 665451 565761 453505 -34810 233427 -68667 268862 790922 677218 29043 1736 -23248 697276 623322 363410 659608 726773 829838 515904 514815 427859 976604 256781 -14411 694001 977543 823971 647500 650553 438123 136557 844251 600870 70155 847635 68949 150563 729301 226996 312323 109078 865068 59371 569643 140799 482907 724512 274590 14812 78145 887349 596104 702062 176317 599886 465750 828702 14768 103365 365783 846563 -85499 826759 555253 78721 961903 919803 908289 451583 318094 292622 910453 827611 227941 494893 584112 655702 450117 -53140 809387 601105 171556 163523 665543 204189 795995 384163 246939 51781 541508 722162 373384 454154 372334 744749 559790 436798 953933 67697 166207 466544 863650 337733 903216 46943 137539 251025 434230 307641 329354 81332 767949 637137 646558 -18509 985930 327801 973624 721056 633574 464511 897346 932852 672931 760759 999149 59695 985736 288494 894701 443885 589910 679724 926400 719196 462730 97599 962663 172863 634398 605293 129017 -69735 588057 443684 626922 109694 234360 -61625 233521 168793 272966 665135 14219 401041 919197 714351 132097 -56829 32140 968487 895926 438857 372180 391888 -54750 303110 97208 184109 101285 370505 377634 679541 276305 167600 786943 764806 332534 245982 213203 206671 786672 481465 397620 687575 461334 543722 442119 950 -99888 719674 375966 601228 202798 354289 619026 678588 369111 214286 980988 23850 746099 9898 553033 898278 52498 275020 762501 700871 69104 458475 237005 89470 256504 793741 13257 477533 440265 69439 209948 10597 34067 -11914 695720 990740 587502 995038 -97479 958946 803335 125907 269318 441226 656181 718115 807193 995814 -44926 509595 994512 759154 647979";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="127589 -24696 549127 78340 291070 91641 548456 295766 732598 155063 353359 471533 202926 410404 293051 162873 790010 303661 199577 22952 -26425 716067 607805 683019 471108 921589 863982 675168 499085 889034 868462 -82481 354285 240870 471680 1180 258793 721459 119540 937521 933636 759369 59004 857296 699438 768879 806979 740832 156622 479554 686549 839283 41255 411444 812209 888610 591183 237334 252636 347955 690762 805860 764320 498415 638789 105670 504257 -18489 8322 337827 297428 856269 -34712 232135 820834 144779 163839 -17696 990896 411518 367968 186242 -63611 649052 26019 339033 119011 686729 995080 793089 859733 1051 995252 884266 928620 315022 651734 685866 720173 327580 635176 707449 -57720 944845 431549 789159 305417 223569 537421 -78402 73731 201092 526254 -75951 530973 237867 550426 705486 763553 605111 281752 901917 341975 941119 809945 344219 563962 332730 174690 483267 822506 774135 887360 284451 701189 237262 482590 622108 879828 640030 798800 228528 431402 620982 451658 87521 -92239 791517 698382 896470 639825 882193 210141 531262 -74053 227459 -25289 840962 -89740 291471 878766 778485 522575 -7781 111224 952138 651713 204795 755206 512172 722838 495639 874990 405986 206595 245145 -769 43556 291879 974712 299125 205105 762697 579880 654705 194644 101331 691578 -24377 553142 166941 -49792 915068 579195 731658 779756 530140 841888 933814 4668 16034 921888 588962 247723 941220 462956 643552 509251 56212 396342 989849 803346 600055 633051 202033 390679 449696 348366 587119 834389 212139 -49092 781331 539528 708973 309569 356721 967570 3846 661826 905309 481966 220080 408347 290898 -55249 -62467 69089 374909 -91294 221626 661633 266307 733359 17665 -9358 732914 521686 115207 969351 -80398 973229 265118 -24031 250761 377644 718753 637463 513823 962320 123282 115856 212355 559696 270127 740155 155542 786010 951248 661544 897655 787106 224469 345567 814067 745580 808481 96262 777569 342623 639800 817975 652902 774937 955101 255413 113950 49763 812406 698812 -11088 207166 617444 151943 -46089 194929 398519 835321 822264 756000 191623 42000 486890 521692 427620 812860 569933 967248 335571 318676 60056 943874 264340 223393 302341 495595 530362 462103 560050 145557 296635 172412 66686 188953 -85338 -94536 64490 -85838 314364 -63455 509766 665022 448402 455256 -8762 574252 47782 965350 667539 -45932 510178 448462 -56969 38663 990427 341096 442787 435624 334161 498677 408648 378010 956097 91985 91064 284969 465734 138682 -60843 207782 465854 963089 638547 -88228 -96536 -78347 -72556 327521 944513 758946 7625 648453 89371 687863 230844 7083 557589 905011 262650 907130 106546 117202 370541 598972 197464 445003 903879 225815 483351 927432 133545 131034 384691 462705 396544 874254 396831 698035 702074 472298 797740 626644 16659 596278 782940 957527 915503 196562 104216 883363 755138 157075 730357 704509 -43974 140893 520756 931554 -97598 223176 281025 659009 431837 754026 951813 268464 165274 89767 813116 499524 518074 26190 385132 248257 334678 495040 671885 509969 549824 571298 325591 911059 531316 706398 329724 167933 106888 378412 176615 863228 292928 942246 674822 791976 735444 433157 796147 69922 607717 722733 31228 277590 243965 262310 -22019 729064 223909 524783 589898 93791 579451 -23941 32656 443313 263301 676886 311365 109240 997008 319536 367221 727627 968704 -98653 650949 533132 430048 -86102 828803 -43800 107021 839801 100810 197503 493753 913541 403446 986469 414706 745547";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

arg="796123 -29802 649721 399957 810660 245125 264828 860737 920380 74283 913419 741836 -51184 242867 618446 775950 551724 753686 553978 801001 136925 284529 567950 764723 919419 155558 599671 784725 234204 638315 498649 188545 268318 619162 883173 514523 663951 727148 526998 683388 131674 636437 813144 -27626 107122 539279 483602 848476 740053 974537 214240 455716 631366 479674 953497 695542 407045 56885 105323 736077 663412 376025 304063 400488 969649 85554 432674 -94246 168738 677255 714791 -19341 713251 730339 115456 910583 501013 942309 250032 940870 760275 9228 541819 301807 161279 76370 988597 581902 371682 -73457 679140 277104 -97847 959503 861180 959029 53996 555344 724701 864244 417313 497194 -12711 206319 585291 80443 -21715 -34644 137607 967435 474406 600481 312816 416665 831744 882607 796308 117823 553040 225272 428303 -35671 381786 -40890 -59945 339794 -25897 322778 19357 104726 8025 775581 652984 182821 662438 330291 421659 366865 52747 106896 634165 703639 916833 871492 894291 764123 605605 236789 703348 -42787 928283 312698 -39759 794768 190939 926669 462283 -93058 433606 364069 810973 643295 705919 125431 250675 415315 964446 44085 -75192 247168 820607 504302 503689 -96043 522783 124862 85134 78465 -450 627680 768865 134515 989791 963773 721477 459596 581072 803261 495196 575554 419085 -15880 53034 447184 967121 414946 991396 908162 154504 107613 -99334 444092 2553 331965 196833 295744 77589 143148 75124 367074 577110 -25109 979541 243513 36562 254512 919982 47720 467818 -16153 -36903 742985 319290 -27762 456832 517772 778509 774800 316516 691404 646072 678305 -28047 18462 190398 416034 979853 99389 4301 82738 544935 818834 46883 -93731 631486 314715 659536 577058 166506 861072 -50512 773317 570519 383732 328823 766294 704660 489589 313530 -92901 22483 547900 68517 302179 28781 246135 642425 123197 286130 554771 558352 394933 732435 824791 884620 792646 835769 428244 678389 75348 259266 586647 564839 122323 415542 440740 863957 692686 -27103 932914 975013 -75481 217498 27191 -28079 975055 458176 392375 446222 -71446 693186 442553 738467 130507 599109 349603 915 837560 53516 -28965 714469 944977 163064 414334 653278 220310 467061 -14286 866873 385469 231616 703425 742675 911593 540451 442246 138015 636587 -59400 729785 357783 913660 745226 969632 711258 786335 -38740 622344 815960 365969 -80324 876571 675700 190546 457859 640046 594565 845473 -35718 -97870 76815 575993 -26203 668241 451232 6423 135182 930694 173027 92625 360638 -86418 231803 810155 472301 109161 250628 747019 505261 194320 438230 608618 962648 343373 184709 828721 299977 810455 476715 711259 552453 888741 118362 984101 784319 224884 -67393 136598 997706 377540 222576 694901 349167 25719 492417 666302 -676 535700 629588 -62423 251670 768473 524407 134203 202041 226215 363645 270641 107666 54641 658833 781025 977574 746695 704042 191232 941393 11122 76537 231168 943640 87833 905967 790768 54399 -64114 427182 301168 89404 576604 6272 231287 382354 73676 125994 854148 441152 353541 646406 632599 935627 497399 137299 799061 158071 -87982 -32585 857325 320359 -62335 137718 500870 402454 583822 849859 323228 65255 581032 746283 758021 852155 274489 421902 438050 286909 33206 822366 2167 458380 479466 65998 123405 572585 809066 399437 875244 810119 449731 152430 707533 924773 136476 672885 673366 305756 737598 160959 -13375 846152 469328 253656 645006 642201 834650 687937 230916 -33565 575501 993541 877257";./push_swap $arg | ./checker_linux $arg; echo "In :";./push_swap $arg | wc -l

```