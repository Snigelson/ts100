/*
 * Translation.c
 *
 *  Created on: 31Aug.,2017
 *      Author: Ben V. Brown
 */
#include "Translation.h"

// TEMPLATES for short names - choose one and use it as base for your
// translation:

//const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
//const char* SettingsShortNames[16][2] = {
//  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
//  /* (<= 4) Sleep temperature                  */ {"STMP"},
//  /* (<= 4) Sleep timeout                      */ {"STME"},
//  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
//  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
//  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
//  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
//  /* (<= 6) Display rotation mode              */ {"DSPROT"},
//  /* (<= 6) Boost enabled                      */ {"BOOST"},
//  /* (<= 4) Boost temperature                  */ {"BTMP"},
//  /* (<= 6) Automatic start mode               */ {"ASTART"},
//  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
//  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
//  /* (<= 8) Settings reset command             */ {"RESET?"},
//  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
//  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
//};

//const enum ShortNameType SettingsShortNameType = SHORT_NAME_DOUBLE_LINE;
//const char* SettingsShortNames[16][2] = {
//  /* (<= 11) Power source (DC or batt)          */ {"Power", "source"},
//  /* (<=  9) Sleep temperature                  */ {"Sleep", "temp"},
//  /* (<=  9) Sleep timeout                      */ {"Sleep", "timeout"},
//  /* (<= 11) Shutdown timeout                   */ {"Shutdown", "timeout"},
//  /* (<= 13) Motion sensitivity level           */ {"Motion", "sensitivity"},
//  /* (<= 13) Temperature in F and C             */ {"Temperature", "units"},
//  /* (<= 13) Advanced idle display mode enabled */ {"Detailed", "idle screen"},
//  /* (<= 13) Display rotation mode              */ {"Display", "orientation"},
//  /* (<= 13) Boost enabled                      */ {"Boost mode", "enabled"},
//  /* (<=  9) Boost temperature                  */ {"Boost", "temp"},
//  /* (<= 13) Automatic start mode               */ {"Auto", "start"},
//  /* (<= 13) Cooldown blink                     */ {"Cooldown", "blink"},
//  /* (<= 16) Temperature calibration enter menu */ {"Calibrate", "temperature?"},
//  /* (<= 16) Settings reset command             */ {"Factory", "Reset?"},
//  /* (<= 16) Calibrate input voltage            */ {"Calibrate", "input voltage?"},
//  /* (<= 13) Advanced soldering screen enabled  */ {"Detailed", "solder screen"},
//};

#ifdef LANG_EN
const char* SettingsLongNames[16] = {
  // These are all the help text for all the settings.
  // No requirements on spacing or length.
  /* Power source (DC or batt)          */ "Power source. Sets cutoff voltage. <DC 10V> <S 3.3V per cell>",
  /* Sleep temperature                  */ "Sleep Temperature <C>",
  /* Sleep timeout                      */ "Sleep Timeout <Minutes/Seconds>",
  /* Shutdown timeout                   */ "Shutdown Timeout <Minutes>",
  /* Motion sensitivity level           */ "Motion Sensitivity <0.Off 1.least sensitive 9.most sensitive>",
  /* Temperature in F and C             */ "Temperature Unit <C=Celsius F=Fahrenheit>",
  /* Advanced idle display mode enabled */ "Display detailed information in a smaller font on the idle screen.",
  /* Display rotation mode              */ "Display Orientation <A. Automatic L. Left Handed R. Right Handed>",
  /* Boost enabled                      */ "Enable front key enters boost mode 450C mode when soldering",
  /* Boost temperature                  */ "Temperature when in \"boost\" mode",
  /* Automatic start mode               */ "Automatically starts the iron into soldering on power up. T=Soldering, S= Sleep mode,F=Off",
  /* Cooldown blink                     */ "Blink the temperature on the cooling screen while the tip is still hot.",
  /* Temperature calibration enter menu */ "Calibrate tip offset.",
  /* Settings reset command             */ "Reset all settings",
  /* Calibrate input voltage            */ "VIN Calibration. Buttons adjust, long press to exit",
  /* Advanced soldering screen enabled  */ "Display detailed information while soldering",
};

const char* SettingsCalibrationWarning = "Please ensure the tip is at room temperature before continuing!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "LOW VOLT";          // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";           // Must be <= 4 chars
const char* SleepingAdvancedString = "Sleeping...";  // <=17 chars
const char* WarningSimpleString = "HOT!";            // Must be <= 4 chars
const char* WarningAdvancedString = "WARNING! TIP HOT!";

const char SettingRightChar = 'R';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_DOUBLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 11) Power source (DC or batt)          */ {"Power", "source"},
  /* (<=  9) Sleep temperature                  */ {"Sleep", "temp"},
  /* (<=  9) Sleep timeout                      */ {"Sleep", "timeout"},
  /* (<= 11) Shutdown timeout                   */ {"Shutdown", "timeout"},
  /* (<= 13) Motion sensitivity level           */ {"Motion", "sensitivity"},
  /* (<= 13) Temperature in F and C             */ {"Temperature", "units"},
  /* (<= 13) Advanced idle display mode enabled */ {"Detailed", "idle screen"},
  /* (<= 13) Display rotation mode              */ {"Display", "orientation"},
  /* (<= 13) Boost enabled                      */ {"Boost mode", "enabled"},
  /* (<=  9) Boost temperature                  */ {"Boost", "temp"},
  /* (<= 13) Automatic start mode               */ {"Auto", "start"},
  /* (<= 13) Cooldown blink                     */ {"Cooldown", "blink"},
  /* (<= 16) Temperature calibration enter menu */ {"Calibrate", "temperature?"},
  /* (<= 16) Settings reset command             */ {"Factory", "reset?"},
  /* (<= 16) Calibrate input voltage            */ {"Calibrate", "input voltage?"},
  /* (<= 13) Advanced soldering screen enabled  */ {"Detailed", "solder screen"},
};
#endif

#ifdef LANG_RU
const char* SettingsLongNames[16] = {
	// These are all the help text for all the settings.
	// No requirements on spacing or length.
	/* Power source (DC or batt)          */ "Источник питания. Установка напряжения отключения. <DC 10V> <S 3.3 V на батарею>",
	/* Sleep temperature                  */ "Температура режима ожидания <С>",
	/* Sleep timeout                      */ "Время до перехода в режим ожидания <Минуты>",
	/* Shutdown timeout                   */ "Время до отключения <Минуты>",
	/* Motion sensitivity level           */ "Акселерометр <0. Выкл. 1. мин. чувствительный 9. макс. чувствительный>",
	/* Temperature in F and C             */ "В чем измерять температуру",
	/* Advanced idle display mode enabled */ "Показывать детальную информацию маленьким шрифтом на домашнем экране",
	/* Display rotation mode              */ "Ориентация дисплея <A. Автоматический, Л. Левая рука, П. Правая рука>",
	/* Boost enabled                      */ "Турбо-режим при удержании кнопки А при пайке ",
	/* Boost temperature                  */ "Температура в турбо-режиме",
	/* Automatic start mode               */ "Автоматический запуск паяльника при включении питания. T=Нагрев, S=Режим ожидания,F=Выкл.",
	/* Cooldown blink                     */ "Показывать температуру на экране охлаждения, пока жало остается горячим.",
	/* Temperature calibration enter menu */ "Калибровка термодатчика.",
	/* Settings reset command             */ "Сброс всех настроек.",
	/* Calibrate input voltage            */ "Калибровка напряжения входа. Настройка кнопками, нажать и удержать чтобы завершить.",
	/* Advanced soldering screen enabled  */ "Показывать детальную информацию при пайке.",
};

const char* SettingsCalibrationWarning = "Убедитесь, что жало остыло до комнатной температуры, прежде чем продолжать!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "БАТ РАЗР";          // Fixed width 8 chars
const char* SleepingSimpleString = "Хррр";           // Must be <= 4 chars
const char* SleepingAdvancedString = "Ожидание...";  // <=17 chars
const char* WarningSimpleString = " АЙ!";            // Must be <= 4 chars
const char* WarningAdvancedString = "ОСТОРОЖНО! ГОРЯЧО";

/*
 * #TODO change support for multibyte constants here
 const char SettingRightChar = 'П';
 const char SettingLeftChar = 'Л';
 const char SettingAutoChar = 'A';*/

const char SettingRightChar = 'R';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"ИстП  "},
  /* (<= 4) Sleep temperature                  */ {"Тожд"},
  /* (<= 4) Sleep timeout                      */ {"Вожд "},
  /* (<= 5) Shutdown timeout                   */ {"Тоткл "},
  /* (<= 6) Motion sensitivity level           */ {"ЧувсДв "},
  /* (<= 6) Temperature in F and C             */ {"ЕдТемп "},
  /* (<= 6) Advanced idle display mode enabled */ {"ИнфОжд "},
  /* (<= 6) Display rotation mode              */ {"ПовЭкр "},
  /* (<= 6) Boost enabled                      */ {"Турбо  "},
  /* (<= 4) Boost temperature                  */ {"Ттур "},
  /* (<= 6) Automatic start mode               */ {"Астарт"},
  /* (<= 6) Cooldown blink                     */ {"Охлажд "},
  /* (<= 8) Temperature calibration enter menu */ {"КалибрТ"},
  /* (<= 8) Settings reset command             */ {"СБРОС?"},
  /* (<= 8) Calibrate input voltage            */ {"КалибрU?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ИнфПай "},
};
#endif

#ifdef LANG_ES
const char* SettingsLongNames[16] = {
	// These are all the help text for all the settings.
	// No requirements on spacing or length.
  /* Power source (DC or batt)          */ "Fuente de energía. Ajusta el límite inferior de voltaje. <DC=10V S=3.3V por celda>",
  /* Sleep temperature                  */ "Temperatura en reposo. <C>",
  /* Sleep timeout                      */ "Tiempo hasta activar reposo. <Minutos>",
  /* Shutdown timeout                   */ "Tiempo hasta apagado. <Minutos>",
  /* Motion sensitivity level           */ "Sensibilidad del movimiento. <0=Apagado 1=El menos sensible 9=El más sensible>",
  /* Temperature in F and C             */ "Unidad de temperatura.",
  /* Advanced idle display mode enabled */ "Display detailed information in a smaller font on the idle screen.",
  /* Display rotation mode              */ "Orientación de la pantalla <A=Automático I=Mano izquierda D=Mano derecha>",
  /* Boost enabled                      */ "Activar el botón \"Boost\" en modo soldadura.",
  /* Boost temperature                  */ "Temperatura en modo \"Boost\". <C>",
  /* Automatic start mode               */ "Iniciar modo soldadura en el encendido. <V=Sí S=Modo reposo F=No>",
  /* Cooldown blink                     */ "Parpadea la temperatura en el enfriamiento si la punta sigue caliente.",
  /* Temperature calibration enter menu */ "Calibrate tip offset.",
  /* Settings reset command             */ "Reset all settings",
  /* Calibrate input voltage            */ "VIN Calibration. Buttons adjust, long press to exit",
  /* Advanced soldering screen enabled  */ "Display detailed information while soldering",
};

const char* SettingsCalibrationWarning = "Please ensure the tip is at room temperature before continuing!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "LOW VOLT";          // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";           // Must be <= 4 chars
const char* SleepingAdvancedString = "Sleeping...";  // <=17 chars
const char* WarningSimpleString = "HOT!";            // Must be <= 4 chars
const char* WarningAdvancedString = "WARNING! TIP HOT!";

const char SettingRightChar = 'R';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
  /* (<= 4) Sleep temperature                  */ {"STMP"},
  /* (<= 4) Sleep timeout                      */ {"STME"},
  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
  /* (<= 6) Display rotation mode              */ {"DSPROT"},
  /* (<= 6) Boost enabled                      */ {"BOOST"},
  /* (<= 4) Boost temperature                  */ {"BTMP"},
  /* (<= 6) Automatic start mode               */ {"ASTART"},
  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
  /* (<= 8) Settings reset command             */ {"RESET?"},
  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
};
#endif

#ifdef LANG_SE
const char* SettingsLongNames[16] = {
	// These are all the help text for all the settings.
	// No requirements on spacing or length.
	/* Power source (DC or batt)          */ "Источник питания. Установка напряжения отключения. <DC 10V> <S 3.3 V на батарею>",
	/* Sleep temperature                  */ "Температура Сна  <С>",
	/* Sleep timeout                      */ "Переход в режим Сна <Минуты>",
	/* Shutdown timeout                   */ "Переходит в режим ожидания <Минуты>",
	/* Motion sensitivity level           */ "Акселерометр <0. Выкл. 1. мин. чувствительный 9. макс. чувствительный>",
	/* Temperature in F and C             */ "В чем измерять температуру",
	/* Advanced idle display mode enabled */ "Display detailed information in a smaller font on the idle screen.",
	/* Display rotation mode              */ "Ориентация Дисплея <A. Автоматический L. Левая Рука R. Правая Рука>",
	/* Boost enabled                      */ "Активация  кнопки A для Турбо режима до  450С при пайке ",
	/* Boost temperature                  */ "Установка температуры для Турбо режима",
	/* Automatic start mode               */ "Автоматический запуск паяльника при включении питания. T=Нагрев, S= Режим Сна,F=Выкл.",
	/* Cooldown blink                     */ "Мигает температура на экране охлаждения, пока жало остается горячим.",
	/* Temperature calibration enter menu */ "Calibrate tip offset.",
	/* Settings reset command             */ "Reset all settings",
	/* Calibrate input voltage            */ "VIN Calibration. Buttons adjust, long press to exit",
	/* Advanced soldering screen enabled  */ "Display detailed information while soldering",
};

const char* SettingsCalibrationWarning = "Please ensure the tip is at room temperature before continuing!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "LOW VOLT";          // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";           // Must be <= 4 chars
const char* SleepingAdvancedString = "Sleeping...";  // <=17 chars
const char* WarningSimpleString = "HOT!";            // Must be <= 4 chars
const char* WarningAdvancedString = "WARNING! TIP HOT!";

const char SettingRightChar = 'R';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
  /* (<= 4) Sleep temperature                  */ {"STMP"},
  /* (<= 4) Sleep timeout                      */ {"STME"},
  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
  /* (<= 6) Display rotation mode              */ {"DSPROT"},
  /* (<= 6) Boost enabled                      */ {"BOOST"},
  /* (<= 4) Boost temperature                  */ {"BTMP"},
  /* (<= 6) Automatic start mode               */ {"ASTART"},
  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
  /* (<= 8) Settings reset command             */ {"RESET?"},
  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
};
#endif

#ifdef LANG_IT
const char* SettingsLongNames[16] = {
  // These are all the help text for all the settings.
  // No requirements on spacing or length.
  /* Power source (DC or batt)          */"Scegli la sorgente di alimentazione; imposta la soglia di scaricamento per alimentazione Li-Po <DC: 10V; S: 3.3V per cella>",
  /* Sleep temperature                  */"Imposta temperatura in modalità standby <°C>",
  /* Sleep timeout                      */"Imposta timer per entrare in modalità standby <minuti/secondi>",
  /* Shutdown timeout                   */"Imposta timer per lo spegnimento <minuti>",
  /* Motion sensitivity level           */"Imposta sensibilità al movimento per uscire dalla modalità standby <0: nessuna; 1: minima; 9: massima>",
  /* Temperature in F and C             */"Scegli l'unità di misura per la temperatura <C: Celsius; F: Farenheit>",
  /* Advanced idle display mode enabled */"Mostra informazioni dettagliate con un carattere più piccolo nella schermata principale",
  /* Display rotation mode              */"Imposta orientamento del display <A: automatico; S: mano sinistra; D: mano destra>",
  /* Boost enabled                      */"Il tasto anteriore attiva la funzione \"boost\" durante la saldatura",
  /* Boost temperature                  */"Imposta la temperatura in funzione \"boost\"",
  /* Automatic start mode               */"Attiva automaticamente il saldatore quando viene alimentato <A: saldatura; S: standby; D: disattiva>",
  /* Cooldown blink                     */"Mostra la temperatura durante il raffreddamento se la punta è ancora calda",
  /* Temperature calibration enter menu */"Calibra la differenza di temperatura rilevata da quella presente sulla punta",
  /* Settings reset command             */"Ripristina tutte le impostazioni",
  /* Calibrate input voltage            */"Calibra la tensione in ingresso; regola con i bottoni, tieni premuto per uscire",
  /* Advanced soldering screen enabled  */"Mostra informazioni dettagliate in modalità saldatura",
};

const char* SettingsCalibrationWarning = "Assicurati che la punta si trovi a temperatura ambiente prima di continuare!";
const char* SettingsResetWarning = "Ripristinare le impostazioni iniziali?";
const char* UVLOWarningString = "LOW VOLT";      // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";       // Must be <= 4 chars
const char* SleepingAdvancedString = "Standby";  // <=17 chars
const char* WarningSimpleString = "HOT!";        // Must be <= 4 chars
const char* WarningAdvancedString = "ATTENZIONE! PUNTA CALDA!";

const char SettingRightChar = 'D';
const char SettingLeftChar = 'S';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_DOUBLE_LINE;
 const char* SettingsShortNames[16][2] = {
    /* (<= 11) Power source (DC or batt)          */ {"Sorgente", "alimentaz"},
    /* (<=  9) Sleep temperature                  */ {"Temp", "standby"},
    /* (<=  9) Sleep timeout                      */ {"Timer", "standby"},
    /* (<= 11) Shutdown timeout                   */ {"Timer", "spegnimento"},
    /* (<= 13) Motion sensitivity level           */ {"Sensibilità", "al movimento"},
    /* (<= 13) Temperature in F and C             */ {"Unità di", "temperatura"},
    /* (<= 13) Advanced idle display mode enabled */ {"Mostra", "dettagli"},
    /* (<= 13) Display rotation mode              */ {"Orientamento", "display"},
    /* (<= 13) Boost enabled                      */ {"Funzione", "\"boost\""},
    /* (<=  9) Boost temperature                  */ {"Temp", "\"boost\""},
    /* (<= 13) Automatic start mode               */ {"Avvio", "automatico"},
    /* (<= 13) Cooldown blink                     */ {"Avviso", "punta calda"},
    /* (<= 16) Temperature calibration enter menu */ {"Calibrazione", "temperatura"},
    /* (<= 16) Settings reset command             */ {"Ripristino", "impostazioni"},
    /* (<= 16) Calibrate input voltage            */ {"Calibrazione", "tensione"},
    /* (<= 13) Advanced soldering screen enabled  */ {"Dettagli", "saldatura"},
};
#endif

#ifdef LANG_FR
const char* SettingsLongNames[16] = {
	// These are all the help text for all the settings.
	// No requirements on spacing or length.
	/* Power source (DC or batt)          */ "Source d'alimentation. Règle la tension de coupure <DC=10V S=3.3V par cellules>",
	/* Sleep temperature                  */ "Température en veille <C>",
	/* Sleep timeout                      */ "Délai avant mise en veille <Minutes>",
	/* Shutdown timeout                   */ "Délai avant extinction <Minutes>",
	/* Motion sensitivity level           */ "Sensibilité du capteur de mouvement <0=Inactif 1=Peu sensible 9=Tres sensible>",
	/* Temperature in F and C             */ "Unité de température <C=Celsius F=Fahrenheit>",
	/* Advanced idle display mode enabled */ "Afficher des informations détaillées lors de la veille",
	/* Display rotation mode              */ "Orientation de l'affichage <A=Automatique G=Gaucher D=Droitier>",
	/* Boost enabled                      */ "Activer le mode \"Boost\" en maintenant le bouton de devant pendant la soudure",
	/* Boost temperature                  */ "Température du mode \"Boost\" <C>",
	/* Automatic start mode               */ "Démarrer automatiquement la soudure à l'allumage",
	/* Cooldown blink                     */ "Faire clignoter la température lors du refroidissement tant que la panne est chaude",
	/* Temperature calibration enter menu */ "Étalonner la température de la panne",
	/* Settings reset command             */ "Réinitialiser tous les réglages",
	/* Calibrate input voltage            */ "Étalonner la tension d'entrée. Boutons pour ajuster, appui long pour quitter",
	/* Advanced soldering screen enabled  */ "Afficher des informations détaillées pendant la soudure",
};

const char* SettingsCalibrationWarning = "Assurez-vous que la panne soit à température ambiante avant de continuer!";
const char* SettingsResetWarning = "Voulez-vous vraiment réinitialiser les paramètres aux valeurs d'usine?";
const char* UVLOWarningString = "LOW VOLT";             // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";              // Must be <= 4 chars
const char* SleepingAdvancedString = "En veille...";    // <=17 chars
const char* WarningSimpleString = "HOT!";               // Must be <= 4 chars
const char* WarningAdvancedString = "ATTENTION! CHAUD"; // Must be <= 16 chars

const char SettingRightChar = 'D';
const char SettingLeftChar = 'G';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_DOUBLE_LINE;
const char* SettingsShortNames[16][2] = {
	/* (<= 11) Power source (DC or batt)          */ {"Source", "d'alim"},
	/* (<=  9) Sleep temperature                  */ {"Temp.", "veille"},
	/* (<=  9) Sleep timeout                      */ {"Délai", "veille"},
	/* (<= 11) Shutdown timeout                   */ {"Délai", "extinction"},
	/* (<= 13) Motion sensitivity level           */ {"Sensibilité", "au mouvement"},
	/* (<= 13) Temperature in F and C             */ {"Unité de", "température"},
	/* (<= 13) Advanced idle display mode enabled */ {"Écran veille", "détaillé"},
	/* (<= 13) Display rotation mode              */ {"Orientation", "de l'écran"},
	/* (<= 13) Boost enabled                      */ {"Activation du", "mode Boost"},
	/* (<=  9) Boost temperature                  */ {"Temp.", "Boost"},
	/* (<= 13) Automatic start mode               */ {"Démarrage", "automatique"},
	/* (<= 13) Cooldown blink                     */ {"Refroidir en", "clignottant"},
	/* (<= 16) Temperature calibration enter menu */ {"Étalonner", "température"},
	/* (<= 16) Settings reset command             */ {"Réinitialisation", "d'usine"},
	/* (<= 16) Calibrate input voltage            */ {"Étalonner", "tension d'entrée"},
	/* (<= 13) Advanced soldering screen enabled  */ {"Écran soudure", "détaillé"},
};
#endif

#ifdef LANG_DE
const char* SettingsLongNames[16] = {
	// These are all the help text for all the settings.
	// No requirements on spacing or length.
	/* Power source (DC or batt)          */ "Spannungsquelle (Abschaltspannung) <DC=10V, nS=n*3.3V für n LiIon-Zellen>",
	/* Sleep temperature                  */ "Ruhetemperatur (In der eingestellten Einheit)",
	/* Sleep timeout                      */ "Ruhemodus nach <Sekunden/Minuten>",
	/* Shutdown timeout                   */ "Abschaltzeit <Minuten>",
	/* Motion sensitivity level           */ "Bewegungsempfindlichkeit <0=Aus, 1=Minimal ... 9=Maximal>",
	/* Temperature in F and C             */ "Temperatureinheit <C=Celsius, F=Fahrenheit>",
	/* Advanced idle display mode enabled */ "Detaillierte Anzeige im Ruhemodus <J=An, N=Aus>",
	/* Display rotation mode              */ "Ausrichtung der Anzeige <A=Automatisch, L=Linkshändig, R=Rechtshändig>",
	/* Boost enabled                      */ "Vordere Taste für Temperaturboost verwenden <J=An, N=Aus>",
	/* Boost temperature                  */ "Temperatur im Boostmodus  (In der eingestellten Einheit)",
	/* Automatic start mode               */ "Automatischer Start des Lötmodus beim Einschalten der Spannungsversorgung. <J=An, N=Aus>",
	/* Cooldown blink                     */ "Blinkende Temperaturanzeige beim Abkühlen, solange heiß. <J=An, N=Aus>",
	/* Temperature calibration enter menu */ "Kalibrierung der Lötspitzentemperatur",
	/* Settings reset command             */ "Alle Einstellungen zurücksetzen",
	/* Calibrate input voltage            */ "Kalibrierung der Eingangsspannung. Kurzer Tastendruck zum Einstellen, langer Tastendruck zum Verlassen.",
	/* Advanced soldering screen enabled  */ "Detaillierte Anzeige im Lötmodus <J=An, N=Aus>",
};

const char* SettingsCalibrationWarning = "Vor dem Fortfahren muss die Lötspitze vollständig abgekühlt sein!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "LOW VOLT";           // Fixed width 8 chars
const char* SleepingSimpleString = "Zzz ";            // Must be <= 4 chars
const char* SleepingAdvancedString = "Ruhemodus...";  // <=17 chars
const char* WarningSimpleString = "HEIß";             // Must be <= 4 chars
const char* WarningAdvancedString = "Achtung! Spitze Heiß!";

const char SettingRightChar = 'R';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_DOUBLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 11) Power source (DC or batt)          */ {"Spannungs-", "quelle"},
  /* (<=  9) Sleep temperature                  */ {"Ruhetemp-", "eratur"},
  /* (<=  9) Sleep timeout                      */ {"Ruhever-", "zoegerung"},
  /* (<= 11) Shutdown timeout                   */ {"Abschalt-", "zeit"},
  /* (<= 13) Motion sensitivity level           */ {"Bewegungs-", "empfindlichk."},
  /* (<= 13) Temperature in F and C             */ {"Temperatur-", "einheit"},
  /* (<= 13) Advanced idle display mode enabled */ {"Detaillierte", "Ruheansicht"},
  /* (<= 13) Display rotation mode              */ {"Anzeige-", "ausrichtung"},
  /* (<= 13) Boost enabled                      */ {"Boosttaste", "aktiv?"},
  /* (<=  9) Boost temperature                  */ {"Boosttemp-", "eratur"},
  /* (<= 13) Automatic start mode               */ {"Start im", "Loetmodus?"},
  /* (<= 13) Cooldown blink                     */ {"Abkuehl-", "blinken?"},
  /* (<= 16) Temperature calibration enter menu */ {"Temperatur", "kalibrieren?"},
  /* (<= 16) Settings reset command             */ {"Einstellungen", "zuruecksetzen?"},
  /* (<= 16) Calibrate input voltage            */ {"Eingangsspannung", "kalibrieren?"},
  /* (<= 13) Advanced soldering screen enabled  */ {"Detaillierte", "Loetansicht"},
};
#endif

#ifdef LANG_SK
const char* SettingsLongNames[16] = {
	// These are all the help text for all the settings.
	// No requirements on spacing or length.
	/* Power source (DC or batt)          */ "Zdroj napatia. Nastavit napatie pre vypnutie (cutoff)  <DC=10V, nS=n*3.3V pre LiIon clanky>",
	/* Sleep temperature                  */ "Kludova teplota (v nastavenych jednotkach)",
	/* Sleep timeout                      */ "Kludovy rezim po <sekundach/minutach>",
	/* Shutdown timeout                   */ "Cas na vypnutie <minuty>",
	/* Motion sensitivity level           */ "Citlivost detekcie pohybu <0=Vyp, 1=Min ... 9=Max>",
	/* Temperature in F and C             */ "Jednotky merania teploty <C=stupne Celzia, F=stupne Fahrenheita>",
	/* Advanced idle display mode enabled */ "Zobrazit detailne informacie v kludovom rezime <T=Zap, F=Vyp>",
	/* Display rotation mode              */ "Orientacia displeja <A=Auto, L=Lavak, R=Pravak>",
	/* Boost enabled                      */ "Povolit tlacidlo pre prudky nahrev <T=Zap, F=Vyp>",
	/* Boost temperature                  */ "Cielova teplota pre prudky nahrev (v nastavenych jednotkach)",
	/* Automatic start mode               */ "Pri starte spustit rezim spajkovania <T=Zap, F=Vyp, S=Spanok>",
	/* Cooldown blink                     */ "Blikanie ukazovatela teploty pocas chladnutia hrotu <T=Zap, F=Vyp>",
	/* Temperature calibration enter menu */ "Kalibracia posunu hrotu",
	/* Settings reset command             */ "Tovarenske nastavenia",
	/* Calibrate input voltage            */ "Kalibracia VIN. Kratke stlacenie meni nastavenie, dlhe stlacenie pre navrat",
	/* Advanced soldering screen enabled  */ "Zobrazenie detailov pocas spajkovania <T=Zap, F=Vyp>",
};

const char* SettingsCalibrationWarning = "Najprv sa prosim uistite, ze hrot ma izbovu teplotu!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "LOW VOLT";               // Fixed width 8 chars
const char* SleepingSimpleString = "Chrr";                // Must be <= 4 chars
const char* SleepingAdvancedString = "Kludovy rezim...";  // <=17 chars
const char* WarningSimpleString = "HOT!";                 // Must be <= 4 chars
const char* WarningAdvancedString = "Pozor! Hrot je horuci!";

const char SettingRightChar = 'R';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
  /* (<= 4) Sleep temperature                  */ {"STMP"},
  /* (<= 4) Sleep timeout                      */ {"STME"},
  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
  /* (<= 6) Display rotation mode              */ {"DSPROT"},
  /* (<= 6) Boost enabled                      */ {"BOOST"},
  /* (<= 4) Boost temperature                  */ {"BTMP"},
  /* (<= 6) Automatic start mode               */ {"ASTART"},
  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
  /* (<= 8) Settings reset command             */ {"RESET?"},
  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
};
#endif

#ifdef LANG_TR
const char* SettingsLongNames[16] = {
	// These are all the help text for all the settings.
	// No requirements on spacing or length.
	/* Power source (DC or batt)          */ "Güç Kaynağı. kesim geriliminı ayarlar. <DC 10V> <S 3.3V hücre başına>",
	/* Sleep temperature                  */ "Uyku Sıcaklığı <C>",
	/* Sleep timeout                      */ "Uyku Zaman Aşımı <Dakika/Saniye>",
	/* Shutdown timeout                   */ "Kapatma Zaman Aşımı <Dakika>",
	/* Motion sensitivity level           */ "Hareket Hassasiyeti <0.Kapalı 1.En az duyarlı 9.En duyarlı>",
	/* Temperature in F and C             */ "Sıcaklık Ünitesi <C=Celsius F=Fahrenheit>",
	/* Advanced idle display mode enabled */ "Boş ekranda ayrıntılı bilgileri daha küçük bir yazı tipi ile göster.",
	/* Display rotation mode              */ "Görüntü Yönlendirme <A. Otomatik L. Solak R. Sağlak>",
	/* Boost enabled                      */ "Lehimleme yaparken ön tuşa basmak Boost moduna sokar(450C)",
	/* Boost temperature                  */ "\"boost\" Modu Derecesi",
	/* Automatic start mode               */ "Güç verildiğinde otomatik olarak lehimleme modunda başlat. T=Lehimleme Modu, S= Uyku Modu,F=Kapalı",
	/* Cooldown blink                     */ "Soğutma ekranında uç hala sıcakken derece yanıp sönsün.",
	/* Temperature calibration enter menu */ "Ucu kalibre et.",
	/* Settings reset command             */ "Bütün ayarları sıfırla",
	/* Calibrate input voltage            */ "VIN Kalibrasyonu. Düğmeler ayarlar, çıkmak için uzun bas.",
	/* Advanced soldering screen enabled  */ "Lehimleme yaparken detaylı bilgi göster",
};

const char* SettingsCalibrationWarning = "Lütfen devam etmeden önce ucun oda sıcaklığında olduğunu garantiye alın!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "LOW VOLT";        // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";         // Must be <= 4 chars
const char* SleepingAdvancedString = "Uyuyor...";  // <=17 chars
const char* WarningSimpleString = "HOT!";          // Must be <= 4 chars
const char* WarningAdvancedString = "UYARI! UÇ SICAK!";

const char SettingRightChar = 'R';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
  /* (<= 4) Sleep temperature                  */ {"STMP"},
  /* (<= 4) Sleep timeout                      */ {"STME"},
  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
  /* (<= 6) Display rotation mode              */ {"DSPROT"},
  /* (<= 6) Boost enabled                      */ {"BOOST"},
  /* (<= 4) Boost temperature                  */ {"BTMP"},
  /* (<= 6) Automatic start mode               */ {"ASTART"},
  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
  /* (<= 8) Settings reset command             */ {"RESET?"},
  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
};
#endif

#ifdef LANG_HR
const char* SettingsLongNames[16] = {
	// These are all the help text for all the settings.
	// No requirements on spacing or length.
	/* Power source (DC or batt)          */ "Izvor napajanja. Postavlja napon isključivanja. <DC 10V> <S 3.3V po ćeliji>",
	/* Sleep temperature                  */ "Temperatura spavanja. <C>",
	/* Sleep timeout                      */ "Vrijeme spavanja. <Minute/Sekunde>",
	/* Shutdown timeout                   */ "Vrijeme gašenja. <Minutes>",
	/* Motion sensitivity level           */ "Osjetljivost prepoznavanja pokreta. <0=Ugašeno, 1=Najmanje osjetljivo, 9=Najosjetljivije>",
	/* Temperature in F and C             */ "Jedinica temperature. <C=Celzij, F=Fahrenheit>",
	/* Advanced idle display mode enabled */ "Prikazivanje detaljnih informacija manjim fontom tijekom čekanja.",
	/* Display rotation mode              */ "Orijentacija ekrana. <A=Automatski, L=Ljevoruki, D=Desnoruki>",
	/* Boost enabled                      */ "Držanjem prednjeg gumba prilikom lemljenja aktivira se pojačani (Boost) način.",
	/* Boost temperature                  */ "Temperatura u pojačanom (Boost) načinu.",
	/* Automatic start mode               */ "Početno stanje lemilice po uključivanju napajanja. <+=Lemljenje, S=Spavanje, -=Ugašeno>",
	/* Cooldown blink                     */ "Bljeskanje temperature prilikom hlađenja, ako je lemilica vruća.",
	/* Temperature calibration enter menu */ "Kalibriranje temperature mjeri razliku temperature vška i temperature drške, dok je lemilica hladna.",
	/* Settings reset command             */ "Vraćanje svih postavki.",
	/* Calibrate input voltage            */ "Kalibracija ulaznog napona. Podešavanje gumbima, dugački pritisak za kraj.",
	/* Advanced soldering screen enabled  */ "Prikazivanje detaljnih informacija tijekom lemljenja.",
};

const char* SettingsCalibrationWarning = "Provjerite da je vršak ohlađen na sobnu temperaturu prije nego što nastavite!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "NAPON!!!";          // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";           // Must be <= 4 chars
const char* SleepingAdvancedString = "Spavanje...";  // <=17 chars
const char* WarningSimpleString = "VRUĆ";            // Must be <= 4 chars
const char* WarningAdvancedString = "OPREZ! Vršak je vruć!";

const char SettingRightChar = 'D';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
  /* (<= 4) Sleep temperature                  */ {"STMP"},
  /* (<= 4) Sleep timeout                      */ {"STME"},
  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
  /* (<= 6) Display rotation mode              */ {"DSPROT"},
  /* (<= 6) Boost enabled                      */ {"BOOST"},
  /* (<= 4) Boost temperature                  */ {"BTMP"},
  /* (<= 6) Automatic start mode               */ {"ASTART"},
  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
  /* (<= 8) Settings reset command             */ {"RESET?"},
  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
};
#endif

#ifdef LANG_CS_CZ
const char* SettingsLongNames[16] = {
  // These are all the help text for all the settings.
  // No requirements on spacing or length
  /* Power source (DC or batt)          */ "Při nižším napětí ukončí pájení <DC=10V, xS=x*3.3V pro LiPo,LiIon...>",
  /* Sleep temperature                  */ "Teplota v režimu spánku.",
  /* Sleep timeout                      */ "Čas do režimu spánku <Minut/Sekund>",
  /* Shutdown timeout                   */ "Čas do automatického vypnutí <Minut>",
  /* Motion sensitivity level           */ "Citlivost detekce pohybu <0=Vyp, 1=Min, ... 9=Max>",
  /* Temperature in F and C             */ "Jednotky měření teploty <C=Celsius, F=Fahrenheit>",
  /* Advanced idle display mode enabled */ "Zobrazit podrobnosti na výchozí obrazovce?",
  /* Display rotation mode              */ "Orientace obrazovky <A=Auto, L=Levák, P=Pravák>",
  /* Boost enabled                      */ "Povolit boost držením předního tlačítka při pájení?",
  /* Boost temperature                  */ "Teplota v režimu boost.",
  /* Automatic start mode               */ "Při startu ihned nahřívat hrot?",
  /* Cooldown blink                     */ "Blikání teploty při chladnutí, dokud je hrot horký?",
  /* Temperature calibration enter menu */ "Kalibrace měření teploty.",
  /* Settings reset command             */ "Obnovení továrního nastavení.",
  /* Calibrate input voltage            */ "Kalibrace vstupního napětí. Tlačítky uprav, podržením potvrď.",
  /* Advanced soldering screen enabled  */ "Zobrazit podrobnosti při pájení?",
};

const char* SettingsCalibrationWarning = "Ujistěte se, že hrot má pokojovou teplotu! ";          // ending space needed
const char* SettingsResetWarning = "Opravdu chcete resetovat zařízení do továrního nastavení?";
const char* UVLOWarningString = "LOW VOLT";              // Fixed width 8 chars
const char* SleepingSimpleString = "Zzz ";               // Must be <= 4 chars
const char* SleepingAdvancedString = "Režim spánku...";  // <=17 chars
const char* WarningSimpleString = "HOT!";                // Must be <= 4 chars
const char* WarningAdvancedString = "!! HORKÝ HROT !!";  // <= 16 chars

const char SettingRightChar = 'P';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_DOUBLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 11) Power source (DC or batt)          */ {"Zdroj", "napájení"},
  /* (<=  9) Sleep temperature                  */ {"Teplota v", "r. spánku"},
  /* (<=  9) Sleep timeout                      */ {"Čas do", "r. spánku"},
  /* (<= 11) Shutdown timeout                   */ {"Čas do", "vypnutí"},
  /* (<= 13) Motion sensitivity level           */ {"Citlivost", "det. pohybu"},
  /* (<= 13) Temperature in F and C             */ {"Jednotky", "teploty"},
  /* (<= 13) Advanced idle display mode enabled */ {"Podrobnosti", "na vých. obr."},
  /* (<= 13) Display rotation mode              */ {"Orientace", "obrazovky"},
  /* (<= 13) Boost enabled                      */ {"Povolit", "boost"},
  /* (<=  9) Boost temperature                  */ {"Teplota v", "r. boost"},
  /* (<= 13) Automatic start mode               */ {"Auto", "start"},
  /* (<= 13) Cooldown blink                     */ {"Blikáni při", "chladnutí"},
  /* (<= 16) Temperature calibration enter menu */ {"Kalibrovat", "teplotu?"},
  /* (<= 16) Settings reset command             */ {"Tovární", "nastavení?"},
  /* (<= 16) Calibrate input voltage            */ {"Kalibrovat", "vstupní napětí?"},
  /* (<= 13) Advanced soldering screen enabled  */ {"Podrobnosti", "při pájení"},
};
#endif

#ifdef LANG_HUN
const char* SettingsLongNames[16] = {
  // These are all the help text for all the settings.
  // No requirements on spacing or length
  /* Power source (DC or batt)          */ "Áramforrás. Beállítja a lekapcsolási feszültséget. <DC 10V> <S 3.3V cellánként>",
  /* Sleep temperature                  */ "Alvási hőmérséklet <C>",
  /* Sleep timeout                      */ "Elalvási időzítő <Perc/Másodperc>",
  /* Shutdown timeout                   */ "Kikapcsolási időzítő <Minutes>",
  /* Motion sensitivity level           */ "Mozgás érzékenység beállítása. <0.Ki 1.kevésbé érzékeny 9.legérzékenyebb>",
  /* Temperature in F and C             */ "Hőmérsékleti egység <C=Celsius F=Fahrenheit>",
  /* Advanced idle display mode enabled */ "Részletes információ megjelenítése kisebb betűméretben a készenléti képernyőn.",
  /* Display rotation mode              */ "Megjelenítési tájolás <A. Automatikus L. Balkezes R. Jobbkezes>",
  /* Boost enabled                      */ "Elülső gombbal lépjen boost módba, 450C forrasztás közben",
  /* Boost temperature                  */ "Hőmérséklet \"boost\" módban",
  /* Automatic start mode               */ "Bekapcsolás után automatikusan lépjen forrasztás módba. T=Forrasztás, S=Alvó mód,F=Ki",
  /* Cooldown blink                     */ "Villogjon a hőmérséklet hűlés közben, amíg a hegy forró.",
  /* Temperature calibration enter menu */ "Hegy hőmérsékletének kalibrálása",
  /* Settings reset command             */ "Beállítások alaphelyzetbe állítása",
  /* Calibrate input voltage            */ "A bemeneti feszültség kalibrálása. Röviden megnyomva állítsa be, hosszan nyomja meg a kilépéshez.",
  /* Advanced soldering screen enabled  */ "Részletes információk megjelenítése forrasztás közben",
};

const char* SettingsCalibrationWarning = "Folytatás előtt győződj meg róla, hogy a hegy szobahőmérsékletű!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "LOW VOLT";       // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";        // Must be <= 4 chars
const char* SleepingAdvancedString = "Alvás...";  // <=17 chars
const char* WarningSimpleString = "HOT!";         // Must be <= 4 chars
const char* WarningAdvancedString = "FIGYELEM! FORRÓ HEGY!";

const char SettingRightChar = 'R';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
  /* (<= 4) Sleep temperature                  */ {"STMP"},
  /* (<= 4) Sleep timeout                      */ {"STME"},
  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
  /* (<= 6) Display rotation mode              */ {"DSPROT"},
  /* (<= 6) Boost enabled                      */ {"BOOST"},
  /* (<= 4) Boost temperature                  */ {"BTMP"},
  /* (<= 6) Automatic start mode               */ {"ASTART"},
  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
  /* (<= 8) Settings reset command             */ {"RESET?"},
  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
};
#endif

#ifdef LANG_DK
const char* SettingsLongNames[16] = {
  // These are all the help text for all the settings.
  // No requirements on spacing or length
  /* Power source (DC or batt)          */ "Strømforsyning. Indstil Cutoff Spændingen. <DC 10V <S 3.3V per cell",
  /* Sleep temperature                  */ "Dvale Temperatur <C",
  /* Sleep timeout                      */ "Dvale Timeout <Minutter/Sekunder",
  /* Shutdown timeout                   */ "sluknings Timeout <Minutter",
  /* Motion sensitivity level           */ "Bevægelsesfølsomhed <0.Slukket 1.Mindst følsom 9.Mest følsom",
  /* Temperature in F and C             */ "Temperatur Enhed <C=Celsius F=Fahrenheit",
  /* Advanced idle display mode enabled */ "Vis detialieret information med en mindre skriftstørrelse på standby skærmen.",
  /* Display rotation mode              */ "Skærm Orientering <A. Automatisk V. Venstre Håndet H. Højre Håndet",
  /* Boost enabled                      */ "Ved tryk på front knap Aktiveres boost-funktionen, 450C tilstand når der loddes",
  /* Boost temperature                  */ "Temperatur i \"boost\" mode",
  /* Automatic start mode               */ "Start automatisk med lodning når strøm sættes til. L=Lodning, D= Dvale tilstand,S=Slukket",
  /* Cooldown blink                     */ "Blink temperaturen på skærmen, mens spidsen stadig er varm.",
  /* Temperature calibration enter menu */ "kalibrere spids temperatur.",
  /* Settings reset command             */ "Gendan alle indstillinger",
  /* Calibrate input voltage            */ "VIN kalibrering. Knapperne justere, Lang tryk for at gå ud",
  /* Advanced soldering screen enabled  */ "Vis detialieret information mens der loddes",
};

const char* SettingsCalibrationWarning = "Sørg for at loddespidsen er ved stuetemperatur, inden du fortsætter!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "Lav Volt";       // Fixed width 8 chars
const char* SleepingSimpleString = "Zzzz";        // Must be <= 4 chars
const char* SleepingAdvancedString = "Dvale...";  // <=17 chars
const char* WarningSimpleString = "Varm";         // Must be <= 4 chars
const char* WarningAdvancedString = "ADVARSEL! VARM LODDESPIDS!";

const char SettingRightChar = 'H';
const char SettingLeftChar = 'V';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
  /* (<= 4) Sleep temperature                  */ {"STMP"},
  /* (<= 4) Sleep timeout                      */ {"STME"},
  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
  /* (<= 6) Display rotation mode              */ {"DSPROT"},
  /* (<= 6) Boost enabled                      */ {"BOOST"},
  /* (<= 4) Boost temperature                  */ {"BTMP"},
  /* (<= 6) Automatic start mode               */ {"ASTART"},
  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
  /* (<= 8) Settings reset command             */ {"RESET?"},
  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
};
#endif

#ifdef LANG_PL
const char* SettingsLongNames[16] = {
    // These are all the help text for all the settings.
    // No requirements on spacing or length
    /* Power source (DC or batt)          */ "Źródło zasilania. Ustaw napięcie odcięcia. <DC 10V> <S 3.3V dla ogniw Li>",
    /* Sleep temperature                  */ "Temperatura uśpienia <°C>",
    /* Sleep timeout                      */ "Czas uśpienia <Minuty/Sekundy>",
    /* Shutdown timeout                   */ "Czas wyłączenia <Minuty>",
    /* Motion sensitivity level           */ "Czułość ruchu <0.Wyłączona 1.minimalna 9.maksymalna>",
    /* Temperature in F and C             */ "Jednostka temperatury <C=Celsius F=Fahrenheit>",
    /* Advanced idle display mode enabled */ "Wyświetla szczegółowe informacje za pomocą mniejszej czcionki na ekranie bezczynnośći <T = wł., N = wył.>",
    /* Display rotation mode              */ "Orientacja wyświetlacza <A. Automatyczna L. Leworęczna P. Praworęczna>",
    /* Boost enabled                      */ "Użyj przycisku przedniego w celu zwiększenia temperatury <T = wł., N = wył.>",
    /* Boost temperature                  */ "Temperatura w trybie \"boost\" ",
    /* Automatic start mode               */ "Automatyczne uruchamianie trybu lutowania po włączeniu zasilania. T=Lutowanie, S= Tryb Uspienia ,N=Wyłącz",
    /* Cooldown blink                     */ "Temperatura na ekranie miga, gdy grot jest jeszcze gorący. <T = wł., N = wył.>",
    /* Temperature calibration enter menu */ "Kalibracja temperatury grota lutownicy",
    /* Settings reset command             */ "Zresetuj wszystkie ustawienia",
    /* Calibrate input voltage            */ "Kalibracja napięcia wejściowego. Krótkie naciśnięcie, aby ustawić, długie naciśnięcie, aby wyjść.",
    /* Advanced soldering screen enabled  */ "Wyświetl szczegółowe informacje podczas lutowania <T = wł., N = wył.>",
};

const char* SettingsCalibrationWarning = "Przed kontynuowaniem upewnij się, że końcówka osiągnela temperature pokojowa!";
const char* SettingsResetWarning = "Are you sure to reset settings to default values?";
const char* UVLOWarningString = "LOW VOLT";          // Fixed width 8 chars
const char* SleepingSimpleString = "Zzz!";           // Must be <= 4 chars
const char* SleepingAdvancedString = "Uspienie...";  // <=17 chars
const char* WarningSimpleString = "HOT!";            // Must be <= 4 chars
const char* WarningAdvancedString = "UWAGA! GORĄCA KOŃCÓWKA!";

const char SettingRightChar = 'P';
const char SettingLeftChar = 'L';
const char SettingAutoChar = 'A';

const enum ShortNameType SettingsShortNameType = SHORT_NAME_SINGLE_LINE;
const char* SettingsShortNames[16][2] = {
  /* (<= 5) Power source (DC or batt)          */ {"PWRSC"},
  /* (<= 4) Sleep temperature                  */ {"STMP"},
  /* (<= 4) Sleep timeout                      */ {"STME"},
  /* (<= 5) Shutdown timeout                   */ {"SHTME"},
  /* (<= 6) Motion sensitivity level           */ {"MSENSE"},
  /* (<= 6) Temperature in F and C             */ {"TMPUNT"},
  /* (<= 6) Advanced idle display mode enabled */ {"ADVIDL"},
  /* (<= 6) Display rotation mode              */ {"DSPROT"},
  /* (<= 6) Boost enabled                      */ {"BOOST"},
  /* (<= 4) Boost temperature                  */ {"BTMP"},
  /* (<= 6) Automatic start mode               */ {"ASTART"},
  /* (<= 6) Cooldown blink                     */ {"CLBLNK"},
  /* (<= 8) Temperature calibration enter menu */ {"TMP CAL?"},
  /* (<= 8) Settings reset command             */ {"RESET?"},
  /* (<= 8) Calibrate input voltage            */ {"CAL VIN?"},
  /* (<= 6) Advanced soldering screen enabled  */ {"ADVSLD"},
};
#endif
