using System;
using System.IO;
using System.Linq;

namespace TiitLab2._3
{
    class Program
    {
        static void Main(string[] args)
        {
            //int[,] graph = new int[,] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            //                          { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            //                          { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            //                          { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            //                          { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            //                          { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            //                          { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            //                          { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            //                          { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
            GFG t = new GFG();

            var matrix = GetMatrix(out var numberOfNodes);


            t.Dijkstra(matrix, 0);
        }

        public static int[,] GetMatrix(out int numberOfNodes)
        {

            var fileData = File.ReadAllLines("05");
            numberOfNodes = int.Parse(fileData.First().Split()[0]);
            var matrix = new int[numberOfNodes, numberOfNodes];

            for (int i = 0; i < numberOfNodes; i++)
            {
                var nodeInfo = fileData[i + 1].Split();
                var node1 = int.Parse(nodeInfo[0]) - 1;
                var node2 = int.Parse(nodeInfo[1]) - 1;
                var weight = int.Parse(nodeInfo[2]);

                matrix[node1, node2] = weight;
                matrix[node2, node1] = weight;
            }

            for (int i = 0; i < numberOfNodes; i++)
            {
                for (int j = 0; j < numberOfNodes; j++)
                {
                    Console.Write(matrix[i, j]);
                    Console.Write(" ");
                }
                Console.WriteLine();
            }
            return matrix;

            //for (int i = 0; i < numberOfNodes; i++)
            //{
            //    for (int j = 0; j < numberOfNodes; j++)
            //    {
            //    }
            //}
        }
    }

    class GFG
    {

        // A utility function to find the 
        // vertex with minimum distance 
        // value, from the set of vertices 
        // not yet included in shortest 
        // path tree 
        static int V = 6;
        int MinDistance(int[] distance,bool[] visited)
        {
            // Initialize min value 
            int min = int.MaxValue, min_index = -1;

            for (int v = 0; v < V; v++)
                if (visited[v] == false && distance[v] <= min)
                {
                    min = distance[v];
                    min_index = v;
                }

            return min_index;
        }

        // A utility function to print 
        // the constructed distance array 
        void PrintSolution(int[] distance, int n)
        {
            Console.Write("Vertex     Distance " + "from Source\n");
            for (int i = 0; i < V; i++)
                Console.Write(i + " \t\t " + distance[i] + "\n");
        }

        // Function that implements Dijkstra's 
        // single source shortest path algorithm 
        // for a graph represented using adjacency 
        // matrix representation 
        public void Dijkstra(int[,] graph, int src)
        {
            int[] distance = new int[V]; // The output array. dist[i] 
                                     // will hold the shortest 
                                     // distance from src to i 

            // sptSet[i] will true if vertex 
            // i is included in shortest path 
            // tree or shortest distance from 
            // src to i is finalized 
            bool[] visited = new bool[V];

            // Initialize all distances as 
            // INFINITE and stpSet[] as false 
            for (int i = 0; i < V; i++)
            {
                distance[i] = int.MaxValue;
                visited[i] = false;
            }

            // Distance of source vertex 
            // from itself is always 0 
            distance[src] = 0;

            // Find shortest path for all vertices 
            for (int count = 0; count < V - 1; count++)
            {
                // Pick the minimum distance vertex 
                // from the set of vertices not yet 
                // processed. u is always equal to 
                // src in first iteration. 
                int u = MinDistance(distance, visited);

                // Mark the picked vertex as processed 
                visited[u] = true;

                // Update dist value of the adjacent 
                // vertices of the picked vertex. 
                for (int v = 0; v < V; v++)

                    // Update dist[v] only if is not in 
                    // sptSet, there is an edge from u 
                    // to v, and total weight of path 
                    // from src to v through u is smaller 
                    // than current value of dist[v] 
                    if (!visited[v] && graph[u, v] != 0 && distance[u] != int.MaxValue && distance[u] + graph[u, v] < distance[v])
                        distance[v] = distance[u] + graph[u, v];
            }

            // print the constructed distance array 
            PrintSolution(distance, V);
        }


    }
}
