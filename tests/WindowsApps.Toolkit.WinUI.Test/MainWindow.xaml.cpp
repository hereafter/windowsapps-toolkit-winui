#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

#include "ConvertersPage.g.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::UI::Xaml::Interop;

using namespace winrt::WindowsApps::Toolkit::WinUI::Test::implementation;

MainWindow::MainWindow()
{
    InitializeComponent();

    this->ContentFrame().Navigate(xaml_typename<ConvertersPage>());
}


