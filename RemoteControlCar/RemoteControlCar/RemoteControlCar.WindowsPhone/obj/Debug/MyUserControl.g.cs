﻿

#pragma checksum "C:\Github\ipeerbhai\FollowMe\RemoteControlCar\RemoteControlCar\RemoteControlCar.Shared\MyUserControl.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "0C385063171D3A1E526A824C57359203"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace RemoteControlCar
{
    partial class MyUserControl : global::Windows.UI.Xaml.Controls.UserControl, global::Windows.UI.Xaml.Markup.IComponentConnector
    {
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.Windows.UI.Xaml.Build.Tasks"," 4.0.0.0")]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
 
        public void Connect(int connectionId, object target)
        {
            switch(connectionId)
            {
            case 1:
                #line 13 "..\..\MyUserControl.xaml"
                ((global::Windows.UI.Xaml.UIElement)(target)).ManipulationStarted += this.Ellipse_ManipulationStarted;
                 #line default
                 #line hidden
                #line 13 "..\..\MyUserControl.xaml"
                ((global::Windows.UI.Xaml.UIElement)(target)).ManipulationDelta += this.Ellipse_ManipulationDelta;
                 #line default
                 #line hidden
                #line 13 "..\..\MyUserControl.xaml"
                ((global::Windows.UI.Xaml.UIElement)(target)).ManipulationCompleted += this.Ellipse_ManipulationCompleted;
                 #line default
                 #line hidden
                break;
            }
            this._contentLoaded = true;
        }
    }
}


