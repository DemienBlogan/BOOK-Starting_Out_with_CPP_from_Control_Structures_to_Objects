#pragma once

#include "PatientAccount.h"

void ShowMainMenu();
void ShowPharmacyMenu();
void ShowSurgeryMenu();
char SelectItem();
void ShowPatientTotalCharges(const PatientAccount& account);
void ShowError();