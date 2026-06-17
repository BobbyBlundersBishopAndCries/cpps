I'm gonna solve this example using the Ford-Jhonson algorthim : ./PmergeMe 8 3 1 4 7 18 2 28 24 5 9 15
### Ford-Jhonson algo :
#### step 1: make pairs each with next making the big one first or second it doesn't matter:
just be consistent on each pair incrementing by 2 
    std::vector<std::pair<unsigned int, unsigned int>> pairs = {(8,3),(4,1),(18,7),(28,2),(24,5),(15,9)};
 or std::deque<std::pair<unsigned int, unsigned int>> pairs = {(8,3),(4,1),(18,7),(28,2),(24,5),(15,9)};
#### step 2: Using merge sort, sort the pairs by first in this case to get this new version of pairs:
pairs = {(4,1),(8,3),(15,9),(18,7),(24,5),(28,2)}

<img width="1612" height="1221" alt="image" src="https://github.com/user-attachments/assets/e143935f-88e1-47d3-8fbd-b58fb2ef3fcd" />

Full visualization :

<img width="1300" height="1734" alt="image" src="https://github.com/user-attachments/assets/bcb4879b-0a0c-40b5-bd72-ba7f2f92ec6b" />

### step 3: Use Jacobsthal order to insert the pend Container:

<img width="1869" height="1376" alt="image" src="https://github.com/user-attachments/assets/1576d079-4c86-44f2-8841-3303297db243" />
