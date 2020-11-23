/*
19. Spectral Analysis
If a scientist knows the wevelength of an electromagnetic wave, he or she can determine
what type of radiation it is. Write a program that asks for the wavelength of
an electromagnetic wave in meters and then displays what that wave is according to
the chart below. (For example, a wave with a wavelength of 1E-10 meters would
be an X-ray).
            1*10^-2         1*10^-3       1*10^-7        4*10^-7         1*10^-8       1*10^-11
               |              |              |              |              |              |
   |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
<-------------------------------------------------------------------------------------------------------->
    Radio Waves|    Microwaves|      Infrared| Visible Light|   Ultraviolet|        X-Rays| Gamma Rays
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the wavelength of an electromagnetic wave (meters): ";
	double wavelength;
	cin >> wavelength;

	if (wavelength >= 1E-2)
		cout << "It's radio wave.\n";
	else if (wavelength >= 1E-3)
		cout << "It's microwave.\n";
	else if (wavelength >= 7E-7)
		cout << "It's infrared wave.\n";
	else if (wavelength >= 4E-7)
		cout << "It's visible light wave.\n";
	else if (wavelength >= 1E-8)
		cout << "It's ultraviolet wave.\n";
	else if (wavelength >= 1E-11)
		cout << "It's X-Ray wave.\n";
	else
		cout << "It's Gamma Ray wave.\n";

	return 0;
}