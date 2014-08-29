using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace RemoteControlCar
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private int m_LeftMotor;
        private int m_RightMotor;
        public MainPage()
        {
            this.InitializeComponent();
            Windows.Graphics.Display.DisplayInformation.AutoRotationPreferences = Windows.Graphics.Display.DisplayOrientations.Landscape;
        }

        private void joystickLeft_LostFocus(object sender, RoutedEventArgs e)
        {
            string foo;
            MyUserControl Joystick = (MyUserControl)sender;
            int y = Joystick.PercentPower;
            foo = e.OriginalSource.ToString();
        }

        private string MakeStringPercent(int inputValue)
        {
            string returnMe = "";
            if (inputValue >= 0)
            {
                returnMe = "+" + inputValue.ToString("D3");
            }
            else
            {
                returnMe = inputValue.ToString("D3");
            }
            return (returnMe);
        }

        private void joystick_ManipulationCompleted(object sender, ManipulationCompletedRoutedEventArgs e)
        {
            MyUserControl Joystick = (MyUserControl)sender;
            string joystickInfo = "";
            // figure out if I'm left or right...
            if (Joystick.Name.Contains("Left"))
            {
                m_LeftMotor = Joystick.PercentPower;
            }
            else
            {
                m_RightMotor = Joystick.PercentPower;
            }
            // Build the string we send..
            joystickInfo = MakeStringPercent(m_LeftMotor);
            joystickInfo += MakeStringPercent(m_RightMotor);

            // Call the Azure class.
            //shazbot.TodoItem myItem = new shazbot.TodoItem();
            //shazbot.TodoItem tdi = new shazbot.TodoItem();
            shazbot.TodoItem AzureConnect = new shazbot.TodoItem();
            AzureConnect.SendString2(joystickInfo);
        }

        private void joystickRight_ManipulationDelta(object sender, ManipulationDeltaRoutedEventArgs e)
        {
            MyUserControl Joystick = (MyUserControl)sender;
            string joystickInfo = "";
            // figure out if I'm left or right...
            if (Joystick.Name.Contains("Left"))
            {
                m_LeftMotor = Joystick.PercentPower;
            }
            else
            {
                m_RightMotor = Joystick.PercentPower;
            }
            // Build the string we send..
            joystickInfo = MakeStringPercent(m_LeftMotor);
            joystickInfo += MakeStringPercent(m_RightMotor);

            // Call the Azure class.
            //shazbot.TodoItem myItem = new shazbot.TodoItem();
            //shazbot.TodoItem tdi = new shazbot.TodoItem();
            shazbot.TodoItem AzureConnect = new shazbot.TodoItem();
            AzureConnect.SendString2(joystickInfo);

        }
    }
}
