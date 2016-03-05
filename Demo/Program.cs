using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Toolkit;

namespace Demo
{
    partial class Program
    {
        static void Main(string[] args)
        {
            //MTimerTest();
            RateEstimatorTest();
        }

        private static void MTimerTest()
        {
            for (int i = 0; i < 10000; i++)
            {
                MTimer timer = new MTimer();
                System.Threading.Thread.Sleep(300);
                Console.WriteLine(timer.GetTime() * 1000);
            }
        }
    }
}
