using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Graph1
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileInput = File.ReadAllLines("Input.txt");

            var nodes = fileInput.SelectMany(line => line.Split(' ').Select(s => int.Parse(s))).Distinct();
            var numberOfNodes = nodes.Count() + 1;
            Console.WriteLine($"Number of nodes: {numberOfNodes-1} ");
           


            List<int>[] edges = new List<int>[numberOfNodes];


            for (int i = 0; i < numberOfNodes; i++)
            {
                edges[i] = new List<int>();
            }
            int numberOfEdges = fileInput.Length;
            Console.WriteLine($"Number of edges: {numberOfEdges}");
          

           
            for (int i = 0; i < numberOfEdges; i++)
            {
                Console.WriteLine($"Edge: {fileInput[i]}");
                var edge = fileInput[i].Split(' ');
                edges[int.Parse(edge[0])].Add(int.Parse(edge[1]));
                edges[int.Parse(edge[1])].Add(int.Parse(edge[0]));

            }
            List<Distance> distances = new List<Distance>();

            for (int i = 1; i < numberOfNodes; i++)
            {
                for (int j = 1; j < numberOfNodes; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    var distance = new Distance()
                    {
                        X = i,
                        Y = j,
                        Distancing = totalNodes(edges, numberOfNodes, i, j)
                    };
                    distances.Add(distance);


                }
            }

            Console.WriteLine("Enter distance :");
            var d = int.Parse(Console.ReadLine());
            var result = distances.Where(e => e.Distancing == d);
            Console.WriteLine("Result: ");
            foreach (var res in result)
            {
                Console.WriteLine($"{res.X} {res.Y}");
            }
            Console.WriteLine("Matrix: ");

            var matrix = GetMatrix(edges, numberOfNodes);
            Console.Write(" ");
            for (int i = 1; i < numberOfNodes; i++)
            {
                Console.Write($" | {i} | ");
            }
            Console.WriteLine("\n_________________________________________________________________________");

            for (int i = 1; i < numberOfNodes; i++)
            {
                Console.Write(i);
                for (int j = 1; j < numberOfNodes; j++)
                {
                    Console.Write(" | " + matrix[i, j] + " | ");
                }
                Console.WriteLine();
            }

          
        }
        
        static int[,] GetMatrix(List<int>[] adjac, int n)
        {
            var matrix = new int[n, n];

            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }

                    if (adjac[i].Contains(j))
                    {
                        matrix[i, j] = 1;
                    }


                }
            }
            return matrix;
        }

        static int totalNodes(List<int>[] adjac, int n, int x, int y)
        {

            Boolean[] visited = new Boolean[n + 1];



            int[] p = new int[n];

            Queue<int> q = new Queue<int>();
            q.Enqueue(x);



            visited[x] = true;

            int m, i;


            while (q.Count != 0)
            {
                m = q.Peek();
                q.Dequeue();
                for (i = 0; i < adjac[m].Count; ++i)
                {
                    int h = adjac[m][i];

                    if (visited[h] != true)
                    {
                        visited[h] = true;


                        p[h] = m;
                        q.Enqueue(h);
                    }
                }
            }


            int count = 0;


            i = p[y];
            while (i != x)
            {

                count++;
                i = p[i];
            }
            return count;
        }
    }
    class Distance
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int Distancing { get; set; }

    }
}
