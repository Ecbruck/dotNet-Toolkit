using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Toolkit;

namespace Demo
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 10000;i++ )
                MTimerTest();
        }

        private static void MTimerTest()
        {

            MTimer timer = new MTimer();
            System.Threading.Thread.Sleep(300);
            Console.WriteLine(timer.GetTime() * 1000);
        }
    }
}
