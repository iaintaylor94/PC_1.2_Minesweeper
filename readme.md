# Programming Challenges
## Problem 1.2: Minesweeper[^1]

### Problem description
This problem takes in a grid of characters, and its dimensions, with the '*'s representing mines and '.'s representing spaces. It then processes it so that the spaces are filled with an integer representing the number of mines surrounding the hole. The program prints this result to the terminal. This program will loop until it recieves a zero for each dimension.


### Example 
> **Input**                 
> 4 4       
> \*...         
> ....        
> .\*..      
> ....      
> 3 5      
> \*\*...         
> .....          
> .\*...        
> 0 0

>**Output**          
>Field #1:      
>\*100           
>2210           
>1\*10           
>1110       
>
> Field #2:           
> \*\*100             
> 33200           
> 1\*100


[^1]: Programming Challenges By S.Skienna and M.Revilla, page 16