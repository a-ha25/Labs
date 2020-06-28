using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter the first number");
           int a = int.Parse(Console.ReadLine());
          

            Console.WriteLine("Enter the second number");
            int b = int.Parse(Console.ReadLine());
  
            int result = (a + b) / 2;
            Console.WriteLine(result);
        }

    }
}
