# Flugreservierungssystem (C, Konsolenanwendung)

Menügestütztes Verwaltungssystem für Flüge mit drei Rollen (**Reisender**, **Mitarbeiter**, **Administrator**).  
Datenhaltung erfolgt über Textdateien (`Files/*.txt`). Dieses Projekt entstand als Studienarbeit (2. Semester).

## Features
- Anmeldung/Benutzerbereiche: Reisender, Mitarbeiter, Administrator
- Fluginformationen einsehen und verwalten
- Reservierungen anlegen/auflisten
- Persistenz über einfache Textdateien

## Projektstruktur
```
projet sdd/
├─ main.c
├─ Admin/          # Admin-Menüs & Funktionen (Header)
├─ Emplye/         # Mitarbeiter-Menüs & Funktionen (Header)
├─ User/           # User-Menüs & Funktionen (Header)
└─ Files/          # Daten (Textdateien: Logins, Flüge, Reservierungen, etc.)
```

> Hinweis: Der Quellcode liegt in Header-Dateien (`.h`) für die Menü-Module. Für ein größeres Projekt empfiehlt sich eine Trennung in `.c` und `.h`, dieses Lernprojekt funktioniert jedoch so.

## Voraussetzungen
- **Windows** (das Projekt nutzt `windows.h` und Konsolenfarben).
- **GCC (MinGW)** oder **MSVC** zum Kompilieren.

## Build & Start (GCC/MinGW)
```bash
# aus dem Projektverzeichnis
gcc -o main.exe main.c
./main.exe
```

## Lizenz
MIT – siehe `LICENSE`.