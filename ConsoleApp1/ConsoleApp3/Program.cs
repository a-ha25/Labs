using System;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            double usdToBel = 2.45;
            double usdToEuro = 0.92;

            Console.WriteLine("Enter number of dollars");
            double usd;
            usd = double.Parse(Console.ReadLine());


            Console.WriteLine("Belarussian rubles = "+ (usd * usdToBel));
            Console.WriteLine("Euros = " + (usd * usdToEuro));
        }
    }
}
