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

// The User Control item template is documented at http://go.microsoft.com/fwlink/?LinkId=234236

namespace RemoteControlCar
{
    public sealed partial class MyUserControl : UserControl
    {
        public double m_positionLastY = 0;
        public int PercentPower
        {
            get
            {
                return ((int)m_positionLastY);
            }
        }
        public MyUserControl()
        {
            this.InitializeComponent();
        }

        private void Ellipse_ManipulationDelta(object sender, ManipulationDeltaRoutedEventArgs e)
        {
            txtOutput.Text = e.Cumulative.Translation.Y.ToString();
            if (e.Cumulative.Translation.Y < -100)
            {
                yTranslator.Y = -100.0;
                m_positionLastY = 100.0;

            }
            else if (e.Cumulative.Translation.Y > 100)
            {
                yTranslator.Y = 100.0;
                m_positionLastY = -100.0;

            }
            else
            {
                yTranslator.Y = e.Cumulative.Translation.Y;
                m_positionLastY = -yTranslator.Y;

            }

        }

        private void Ellipse_ManipulationStarted(object sender, ManipulationStartedRoutedEventArgs e)
        {
            e.Handled = true;
        }

        private void Ellipse_ManipulationCompleted(object sender, ManipulationCompletedRoutedEventArgs e)
        {
            yTranslator.Y = 0.0;
        }
    }
}
