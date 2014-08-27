using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Speech;

namespace SpeachPart
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Speech.Synthesis.SpeechSynthesizer mySynth = new System.Speech.Synthesis.SpeechSynthesizer();
            mySynth.Speak("Step 1. Cut one carrot into slices.");
            mySynth.Speak("Step 2. Put the carrot slices into the pot of water.");
            mySynth.Speak("Step 3. Boil the water.");
        }
    }
}
