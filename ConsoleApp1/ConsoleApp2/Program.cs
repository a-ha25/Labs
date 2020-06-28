using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter the first number");
            int firstValue = int.Parse(Console.ReadLine());

            Console.WriteLine("Enter the second number");
            int secondValue = int.Parse(Console.ReadLine());

            Console.WriteLine("Enter the third number");
            int thirdValue = int.Parse(Console.ReadLine());

            int composition = firstValue * secondValue * thirdValue;
            Console.WriteLine("Composition= "+ composition);
          
            int addition = firstValue + secondValue + thirdValue;
            Console.WriteLine("Addition= "+ addition);
           
           

        }
    }
}
