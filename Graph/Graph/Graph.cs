using System;
using System.Collections.Generic;
using System.Text;

namespace Graph
{
    class Graph
    {

        List<Vertex> Vertexes = new List<Vertex>();
        List<Edge> Edges = new List<Edge>();

        public int VertexCount => Vertexes.Count;

        public int EdgesCount => Edges.Count;

        public void AddVertex(Vertex vertex)
        {
            Vertexes.Add(vertex);
        }

        public void AddEdge(Vertex from, Vertex to)
        {
            var edge = new Edge(from, to);
            Edges.Add(edge);
        }

        public int[,] GetMatrix()
        {
            var matrix = new int[Vertexes.Count, Edges.Count];

            foreach (var edge in Edges)
            {
                var row = edge.From.Number - 1;

                var column = edge.To.Number - 1;


                matrix[row, column] = edge.Weight;
            }

            return matrix;
        }
    }
}
