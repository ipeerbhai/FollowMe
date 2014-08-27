using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CannedDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] SerialPorts;
            int numberSerialPorts;
            try
            {
                SerialPorts = System.IO.Ports.SerialPort.GetPortNames();
                numberSerialPorts = SerialPorts.Count();
                if (numberSerialPorts > 0)
                {
                    System.IO.Ports.SerialPort myPort = new System.IO.Ports.SerialPort(SerialPorts[numberSerialPorts - 1], 38400, System.IO.Ports.Parity.None, 8, System.IO.Ports.StopBits.One);
                    myPort.Open();

                    System.IO.StreamReader myReader = new System.IO.StreamReader(myPort.BaseStream);
                    do
                    {
                        string myLine = myPort.ReadLine();
                        if (myLine.Contains(@"ready"))
                        {
                            // We can transmit what to do...
                            System.Console.WriteLine("Sending: +025+025");
                            myPort.Write("+025+025");
                            System.Threading.Thread.Sleep(1000);
                            System.Console.WriteLine("Sending: +050+025");
                            myPort.Write("+050+025");
                            System.Console.WriteLine("Robot is not ready");
                            System.Threading.Thread.Sleep(1000);
                            System.Console.WriteLine("Sending: -025+025");
                            myPort.Write("-025+025");
                            System.Threading.Thread.Sleep(1000);
                        }
                        else
                        {
                            System.Console.WriteLine("Robot is not ready");
                        }
                        if ( myLine.Length == 0)
                        {
                            myPort.Close();
                            myPort.Open();
                        }
                        System.Console.WriteLine(myLine);
                    } while (true);
                    System.Threading.Thread.Sleep(1000);
                }
            }
            catch (Exception e)
            {
                System.Console.WriteLine("No valid serial ports: " + e.Message);
            }

        }
    }
}
