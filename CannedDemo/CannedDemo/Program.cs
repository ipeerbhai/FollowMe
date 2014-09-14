using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Speech;

namespace CannedDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            // Get and init the speech Synthesizer
            System.Speech.Synthesis.SpeechSynthesizer mySynth = new System.Speech.Synthesis.SpeechSynthesizer();
            var Voices = mySynth.GetInstalledVoices();
            if (Voices[1] == null)
            {
                mySynth.SelectVoice(Voices[0].VoiceInfo.Name);
            }
            else
            {
                mySynth.SelectVoice(Voices[1].VoiceInfo.Name);
            }

            mySynth.Speak("Starting up");

            // Get an init a serial port
            string[] SerialPorts;
            int numberSerialPorts;

            try
            {
                SerialPorts = System.IO.Ports.SerialPort.GetPortNames();
                numberSerialPorts = SerialPorts.Count();
                if (numberSerialPorts > 0)
                {
                    System.IO.Ports.SerialPort myPort = new System.IO.Ports.SerialPort(SerialPorts[numberSerialPorts - 1], 115200, System.IO.Ports.Parity.None, 8, System.IO.Ports.StopBits.One);
                    myPort.Open();
                    System.Console.WriteLine("Got Serial Port" + myPort.PortName);

                    System.IO.StreamReader myReader = new System.IO.StreamReader(myPort.BaseStream);
                    do
                    {
                        string myLine = myPort.ReadLine();
                        System.Console.WriteLine("READ: " + myLine);
                        if (myLine.Contains(@"ready"))
                        {
                            // We can transmit what to do...

                            mySynth.Speak("WARNING: moving backwards.");
                            System.Console.WriteLine("Sending: -005-005");
                            myPort.Write("-005-005");
                            System.Threading.Thread.Sleep(1000);

                            mySynth.Speak("WARNING: moving backwards.");
                            System.Console.WriteLine("Sending: -010-010");
                            myPort.Write("-010-010");
                            System.Threading.Thread.Sleep(1000);
                            
                            mySynth.Speak("Backwards Slight Left");
                            System.Console.WriteLine("Sending: -020-025");
                            myPort.Write("-010-020");
                            System.Threading.Thread.Sleep(1000);

                            mySynth.Speak("Bsackwards Slight Right");
                            System.Console.WriteLine("Sending: -025-020");
                            myPort.Write("-020-010");
                            System.Threading.Thread.Sleep(1000);
 
                            mySynth.Speak("Going Forwards");
                            System.Console.WriteLine("Sending: +020+020");
                            myPort.Write("+020+020");
                            System.Threading.Thread.Sleep(3000);

                            mySynth.Speak("Stopping for 5 seconds");
                            System.Console.WriteLine("Sending: +101+101");
                            myPort.Write("+001+001");
                            System.Threading.Thread.Sleep(100);
                            myPort.Write("+101+101");
                            System.Threading.Thread.Sleep(5000);
                        }
                        else
                        {
                            System.Console.WriteLine("Robot is not ready");
                        }
                        if (myLine.Length == 0)
                        {
                            myPort.Close();
                            myPort.Open();
                        }
                        System.Console.WriteLine(myLine);
                    } while (true);
                }
            }
            catch (Exception e)
            {
                System.Console.WriteLine("No valid serial ports: " + e.Message);
                System.Threading.Thread.Sleep(1000);
            }

        }
    }
}
