using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ClassLibrary
{
    public class BinaryTree
    {
        public Node _root;
        public BinaryTree()
        {
            _root = null;
        }

        public void Insert(int[] array)
        {

            _root = new Node();
            Insert(array, _root, 0, array.Length - 1);

        }

        private void Insert(int[] array, Node node, int l, int r)
        {
            node.Data = array.Max();
            node.LeftIndex = l;
            node.RightIndex = r;

            if (array.Length == 1)
            {
                return;
            }

            var firstHalfCount = array.Length == 2 ? 1 : (array.Length / 2) + 1;

            var firstHalf = array.Take(firstHalfCount).ToArray();
            var secondHalf = array.Skip(firstHalfCount).ToArray();
            if (firstHalf.Any())
            {
                node.Left = new Node();
                Insert(firstHalf, node.Left, l, (l + r) / 2);
            }
            if (secondHalf.Any())
            {
                node.Right = new Node();
                Insert(secondHalf, node.Right, (l + r) / 2 + 1, r);
            }
        }

        
        public int FindMax(int queryStart, int queryEnd)
        {
            return FindMax(_root, queryStart, queryEnd, _root.Add);
        }


        private int FindMax(Node node, int queryStart, int queryEnd, int sumAdd)
        {

            if ((node.LeftIndex >= queryStart && node.RightIndex <= queryEnd))
            {
                return node.Data + sumAdd;
            }
            else if ((node.LeftIndex > queryEnd || node.RightIndex < queryStart))
            {
                return int.MinValue;
            }
            return Math.Max(FindMax(node.Left, queryStart, queryEnd, node.Left.Add + sumAdd), FindMax(node.Right, queryStart, queryEnd, node.Right.Add + sumAdd));
        }

        public void Modify(int start, int end, int value)
        {

            Modify(_root, start, end, value);

        }
        private void Modify(Node node, int queryStart1, int queryEnd1, int value)
        {
            if (node.LeftIndex >= queryStart1 && node.RightIndex <= queryEnd1)
            {

                node.Add += value;
                return;
            }
            else
            {

                if (node.Left != null)
                {
                    Modify(node.Left, queryStart1, queryEnd1, value);
                }

                if (node.Right != null)
                {
                    Modify(node.Right, queryStart1, queryEnd1, value);
                }
            }

        }
    }
}
