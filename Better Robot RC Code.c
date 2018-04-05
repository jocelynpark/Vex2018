#pragma config(Sensor, in1,    liftAngle,      sensorPotentiometer)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftFront,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightArmT,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           leftArmT,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           frontMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightArmB,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           leftArmB,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          mobileGoal,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Code for VEX 11040B


task main()
{
	int leftSpeed;
	int rightSpeed;
	int armBaseSpeed;
	int rightArmSpeed;
	int leftArmSpeed;
	int grabberSpeed;
	int mobileGoalSpeed;

	while (true)
	{

		//Controls Right Front Wheel
		if (vexRT[Ch2] > -15 && vexRT[Ch2] < 15)
		{
			rightSpeed = 0;
		}
		else
		{
			rightSpeed = vexRT[Ch2];
		}

		//Controls Left Front Wheel
		if (vexRT[Ch3] > -15 && vexRT[Ch3] < 15)
		{
			leftSpeed = 0;
		}
		else
		{
			leftSpeed = vexRT[Ch3];
		}

		//Controls arm movement
		if (vexRT[Btn6U]==1 && SensorValue[liftAngle] > 1800) {
			armBaseSpeed = -110;
			grabberSpeed = 0;
		}
		else if (vexRT[Btn6D]==1 && SensorValue[liftAngle] < 1800) {
			armBaseSpeed = 110;
			//grabberSpeed = -30;
		}
		else {
			armBaseSpeed = 0;
			grabberSpeed = 0;
		}

		//Controls pinchers movement
		if (vexRT[Btn8U]==1)
		{
			grabberSpeed = 30;
		}
		else if (vexRT[Btn7U]==1)
		{
			grabberSpeed = -30;
		}
		else
		{
			grabberSpeed = 0;
		}

		if (vexRT[Btn5U]==1)
		{
			mobileGoalSpeed = 127;
		}
		else if (vexRT[Btn5D]==1)
		{
			mobileGoalSpeed = -50;
		}
		else
		{
			mobileGoalSpeed = 0;
		}


		motor[leftFront] = leftSpeed;
		motor[leftBack] = leftSpeed;
		motor[rightFront] = rightSpeed;
		motor[rightBack] = rightSpeed;
		motor[rightArmT] = armBaseSpeed;
		motor[rightArmB] = armBaseSpeed;
		motor[leftArmT] = armBaseSpeed;
		motor[leftArmB] = armBaseSpeed;
		motor[frontMotor] = grabberSpeed;
	}


}