using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Toolkit;

namespace Demo
{
    partial class Program
    {
        static void RateEstimatorTest()
        {
            RateEstimator est = new RateEstimator();

            Task.Factory.StartNew(() =>
            {
                int count = 0;
                while (true)
                {
                    for (int i = 0; i < 30; i++)
                    {
                        System.Threading.Thread.Sleep(100);
                        est.AddNewSum(count++);
                    }
                    for (int j = 0; j < 300; j++)
                    {
                        System.Threading.Thread.Sleep(10);
                        est.AddNewSum(count++);
                    }
                }
            }, TaskCreationOptions.LongRunning);

            while (true)
            {
                System.Threading.Thread.Sleep(222);
                Console.WriteLine(est.GetSlop());
            }
        }
    }
}
