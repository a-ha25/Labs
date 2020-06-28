using System;
using System.Linq;
using System.Threading.Tasks;
using System.Collections.Concurrent;
using System.Text;
namespace Graph
{

    class Program
    {
        static void Main(string[] args)
        {
            var graph = new Graph();


            var v1 = new Vertex(1);
            var v2 = new Vertex(2);
            var v3 = new Vertex(3);
            var v4 = new Vertex(4);
            var v5 = new Vertex(5);
            var v6 = new Vertex(6);
            var v7 = new Vertex(7);

            graph.AddVertex(v1);
            graph.AddVertex(v2);
            graph.AddVertex(v3);
            graph.AddVertex(v4);
            graph.AddVertex(v5);
            graph.AddVertex(v6);
            graph.AddVertex(v7);

            graph.AddEdge(v1, v2);
            graph.AddEdge(v1, v3);
            graph.AddEdge(v3, v4);
            graph.AddEdge(v2, v5);
            graph.AddEdge(v2, v6);
            graph.AddEdge(v6, v5);
            graph.AddEdge(v5, v6);




            var matrix = graph.GetMatrix();

            for (int i = 0; i < graph.VertexCount; i++)
            {
                Console.Write(i + 1);
                for (int j = 0; j < graph.VertexCount; j++)
                { 
                    Console.Write(" | " + matrix[i, j] + " | ");
                }
                Console.WriteLine();
            }
            Console.WriteLine("_________________________________________________________________________");
            for (int i = 0; i < graph.VertexCount; i++)
            {
                Console.Write($" | {i+1} | "); 
            }

            Console.ReadLine();
        }
    }

}
