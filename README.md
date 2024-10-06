## PROJECT NAME: Graph and Ranking for LAN Party

##Program Execution
./checker.sh

## Description
The data is read from the input file to simulate a LAN Party tournament. At the end of the simulation, a directed graph is constructed, and the prestige is calculated based on the number of victories obtained by each team. The ranking resembles the PageRank algorithm[1]:

## Requirements:
 ### Task_1:
Teams will be represented by the vertices of the graph, and their position in the file will also determine their position in the graph, being used to create the adjacency matrix. The path between two teams is from the team that lost to the team that won.

 ### Task_2:
The prestige of each team is calculated based on the number of victories obtained and the weight of the tournament, in this case, the weight being q = 0.15, according to the formula[2]:

[1]: Sergey Brin and Lawrence Page. The anatomy of a large-scale hypertextual web search engine. Computer Networks and ISDN Systems, Proceedings of the Seventh International World Wide Web Conference, 30(1):107–117, 1998.
https://snap.stanford.edu/class/cs224w-readings/Brin98Anatomy.pdf

[2]: Pr = (q * pow((2 - q), r)) / (pow(2, l) + pow((2 - q), l) * (q - 1));<br>
q - represents the weight<br>
l - height of the tree<br>
