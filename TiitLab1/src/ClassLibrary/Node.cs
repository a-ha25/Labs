using System;
using System.Collections.Generic;
using System.Text;

namespace ClassLibrary
{
    public class Node
    {
        public int Data { get; set; }
        public int Add { get; set; }
        public int LeftIndex { get; set; }
        public int RightIndex { get; set; }
        public Node Left { get; set; }
        public Node Right { get; set; }
        public Node()
        {

        }
        public Node(int data)
        {
            Data = data;

        }
    }
}
