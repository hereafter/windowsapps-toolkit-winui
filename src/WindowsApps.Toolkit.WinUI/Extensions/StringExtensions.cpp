#include "pch.h"
#include "StringExtensions.h"
#if __has_include("Extensions.StringExtensions.g.cpp")
#include "Extensions.StringExtensions.g.cpp"
#endif

using namespace winrt::WindowsApps::Toolkit::WinUI::Extensions::implementation;
using namespace winrt;
using namespace winrt::Windows::UI;

ResourceLoader StringExtensions::__independentLoader{ nullptr };

ResourceLoader& StringExtensions::IndependentLoader()
{
	if (__independentLoader == nullptr)
	{
		try 
		{
			__independentLoader = ResourceLoader::GetForViewIndependentUse();
		}
		catch (...) {}
	}

	return __independentLoader;
}


hstring StringExtensions::GetLocalized(hstring const& resourceKey)
{
	UIContext context{ nullptr };
	return StringExtensions::GetLocalized(resourceKey, context);
}

hstring StringExtensions::GetLocalized(hstring const& resourceKey, Windows::UI::UIContext uiContext)
{
	if (uiContext != nullptr)
	{
		auto resourceLoader = ResourceLoader::GetForUIContext(uiContext);
		return resourceLoader.GetString(resourceKey);
	}
	else
	{
		return IndependentLoader().GetString(resourceKey);
	}
}

hstring StringExtensions::GetLocalized(hstring const& resourceKey, hstring const& resourcePath)
{
	auto&& loader = IndependentLoader();
	if (loader != nullptr)
	{
		auto result = loader.GetString(resourceKey);
		if (result.size() != 0) return result;
	}
	return ResourceLoader::GetForViewIndependentUse(resourcePath).GetString(resourceKey);
}