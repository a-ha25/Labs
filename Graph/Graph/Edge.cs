using System;
using System.Collections.Generic;
using System.Text;

namespace Graph
{
    class Edge
    {
        public Vertex From { get; set; }
        public Vertex To { get; set; }
        public int Weight { get; set; }

        //public int Belonging { get; set; }
        public Edge(Vertex from, Vertex to, int weight = 1)
        {
            From = from;
            To = to;
            //Belonging = belonging;

            Weight = weight;
        }

        public override string ToString()
        {
            return $"({From}),({To})";
        }
    }
}
