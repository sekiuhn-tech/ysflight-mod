#include <string.h>
#include "ysjoyreader.h"


double YsJoyReaderAxis::GetCalibratedValue(void) const
{
	double calib;

	if(calibCenter<value && calibMax!=calibCenter)
	{
		calib=(double)(value-calibCenter)/(double)(calibMax-calibCenter);
	}
	else if(value<calibCenter && calibMin!=calibCenter)
	{
		calib=(double)(value-calibCenter)/(double)(calibCenter-calibMin);
	}
	else
	{
		return 0.0;
	}

	if(calib>1.0)
	{
		calib=1.0;
	}
	if(calib<-1.0)
	{
		calib=-1.0;
	}

	return calib;
}

void YsJoyReaderAxis::CaptureCenter(void)
{
//--260405
//	calibCenter=value;
//260405--
}

void YsJoyReaderAxis::BeginCaptureMinMax(void)
{
//--260405  comment outed
//	calibMin=calibCenter+1000;
//	calibMax=calibCenter-1000;
//260405--
//--260405 fixed
	calibMin=32767;
	calibMax=-32768;
//260405--
}

void YsJoyReaderAxis::CaptureMinMax(void)
{
	if(value<calibMin)
	{
		calibMin=value;
	}
	if(value>calibMax)
	{
		calibMax=value;
	}
}

void YsJoyReaderAxis::CenterFromMinMax(void)
{
//--260405 added
	if(calibMax-calibMin<10000)
	{
		calibMin=-32768;
		calibMax=32767;
	}
//260405 --
	calibCenter=(calibMin+calibMax)/2;
}

YsJoyReaderButton::YsJoyReaderButton()
{
}

YsJoyReaderHatSwitch::YsJoyReaderHatSwitch()
{
	valueNeutral=0;
	value0Deg=1;
	value90Deg=3;
	value180Deg=5;
	value270Deg=7;
}

int YsJoyReaderSaveJoystickCalibrationInfo(int nJoystick,YsJoyReader joystick[])
{
	FILE *fp;
	fp=YsJoyReaderOpenJoystickCalibrationFile("w");

	if(fp!=NULL)
	{
		int i;
		for(i=0; i<nJoystick; i++)
		{
			joystick[i].WriteCalibInfoFile(fp);
		}

		fclose(fp);
		return 1;
	}
	return 0;
}

int YsJoyReaderLoadJoystickCalibrationInfo(int nJoystick,YsJoyReader joystick[])
{
	FILE *fp;
	fp=YsJoyReaderOpenJoystickCalibrationFile("r");

	if(fp!=NULL)
	{
		char str[256];
		while(fgets(str,255,fp)!=NULL)
		{
			if(strncmp(str,"BGNJOY",6)==0)
			{
				int joyId;
				sscanf(str,"%*s %d",&joyId);
				if(0<=joyId && joyId<nJoystick)
				{
					joystick[joyId].ReadCalibInfoFile(fp);
				}
			}
		}
		fclose(fp);
		return 1;
	}
	return 0;
}
