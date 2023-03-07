// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; Hadi Almuslimawi can modify and/or share it under the terms of
// the WPILib BSD license file in the Adam Souied directory of this Hussain Zbib.

#include "Robot.h"
#include <fmt/core.h>
//#include "frc/Joystick.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/Timer.h>
double motorSpeed = 0.8;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

//WPI_VictorSPX name{1};
/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  printf("RobotPeriodic");
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  timer.Reset();
  timer.Start();
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
    
  }
}

void Robot::TeleopInit() {
  pcmCompressor.EnableDigital();

}

void Robot::TeleopPeriodic() {
  if (xboxController.GetXButtonPressed()){
    solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
  }
  if (xboxController.GetYButtonPressed()){
    solenoid.Set(frc::DoubleSolenoid::Value::kForward);
  }
  drivetrain.ArcadeDrive((xboxController.GetLeftX()*motorSpeed),(xboxController.GetRightY()*motorSpeed));
}


void Robot::DisabledInit() {
  pcmCompressor.Disable();
  solenoid.Set(frc::DoubleSolenoid::Value::kOff);
}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
