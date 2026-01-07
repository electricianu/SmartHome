//---------------exemple /-------pornire nod-----------------------


#include <SmartHomeLib.h>
#include "main/MainBoard.h"

MainBoard board;

void setup() {
    board.begin();
}

void loop() {
    board.loop();
}
//---------------------------------camera inteligenta---------------------------------

#include <SmartHomeLib.h>
#include "main/MainBoard.h"

MainBoard board;

void setup() {
    board.begin();

    // SCENE
    board.sceneManager.addScene(Scene("relax", [](){
        board.mainLight.fadeTo(30);
        board.media.play("relax.mp3");
    }));

    board.sceneManager.addScene(Scene("focus", [](){
        board.mainLight.fadeTo(70);
        board.media.play("focus.mp3");
    }));

    // REGULI DSL
    when(board.ruleEngine, [](const Event& e){
        return e.type == "sensor.motion" && e.value == 1;
    }).Do([](){
        board.mainLight.fadeTo(60);
    });

    when(board.ruleEngine, [](const Event& e){
        return e.type == "location.entered";
    }).Do([](){
        board.sceneManager.load("relax");
    });

    when(board.ruleEngine, [](const Event& e){
        return e.type == "system.low_power";
    }).Do([](){
        board.mainLight.off();
        board.media.tts("Mod economisire energie");
    });

    // EVENIMENTE DIRECTE
    board.eventBus.on([](Event e){
        if (e.type == "intercom.call_incoming") {
            board.media.notify("ding_dong");
            board.mainLight.fadeTo(80);
        }

        if (e.type == "access.approved") {
            board.media.tts("Bine ai venit");
        }
    });
}

void loop() {
    board.loop();
}
//-------------------------------------- Telefon + Scene + Interfon------------------------------

#include <SmartHomeLib.h>
#include "main/MainBoard.h"

MainBoard board;

void setup() {
    board.begin();

    // SCENE
    board.sceneManager.addScene(Scene("evening", [](){
        board.mainLight.fadeTo(40);
        board.media.play("ambient.mp3");
    }));

    board.sceneManager.addScene(Scene("night", [](){
        board.mainLight.off();
        board.media.stop();
        board.access.restrict(board.eventBus, "night_mode");
    }));

    // REGULI PENTRU TELEFON
    when(board.ruleEngine, [](const Event& e){
        return e.type == "phone.command" && e.source == "scene.evening";
    }).Do([](){
        board.sceneManager.load("evening");
    });

    when(board.ruleEngine, [](const Event& e){
        return e.type == "phone.command" && e.source == "scene.night";
    }).Do([](){
        board.sceneManager.load("night");
    });

    // INTERFON
    board.eventBus.on([](Event e){
        if (e.type == "intercom.call_incoming") {
            board.media.notify("ding_dong");
        }

        if (e.type == "intercom.door_open_request") {
            board.access.approve(board.eventBus, "intercom");
            board.yala.on();
        }
    });
}

void loop() {
    board.loop();
}

//------------------------------------exemplu complet------------------------------------------

#include <Arduino.h>
#include "main/MainBoard.h"

// Nodul tău inteligent
MainBoard room;

// ---------- CONFIGURARE SCENE ----------

void setupScenes() {
    // Scena de seară – lumina caldă, muzică ambientală
    room.sceneManager.addScene(Scene("evening", []() {
        room.mainLight.fadeTo(40);
        room.media.play("ambient_evening.mp3");
        room.media.tts("Scena de seara este activa");
    }));

    // Scena de noapte – totul off, mod protejat
    room.sceneManager.addScene(Scene("night", []() {
        room.mainLight.off();
        room.media.stop();
        room.access.restrict(room.eventBus, "night_mode");
        room.media.tts("Mod noapte activat");
    }));

    // Scena relax – lumină jos, muzică liniștită
    room.sceneManager.addScene(Scene("relax", []() {
        room.mainLight.fadeTo(25);
        room.media.play("relax.mp3");
    }));

    // Scena focus – lumină mai puternică, muzică de concentrare
    room.sceneManager.addScene(Scene("focus", []() {
        room.mainLight.fadeTo(70);
        room.media.play("focus.mp3");
    }));

    // Scena welcome_home – compusă din evening + mesaj
    room.sceneManager.addScene(Scene("welcome_home", []() {
        room.sceneManager.load("evening");
        room.media.tts("Bine ai venit acasa");
    }));
}

// ---------- REGULI DSL ----------

void setupRules() {
    // 1. Mișcare în cameră → aprindere lumină la 60%
    when(room.ruleEngine, [](const Event& e) {
        return e.type == "sensor.motion" && e.value == 1;
    }).Do([]() {
        room.mainLight.fadeTo(60);
    });

    // 2. Lipsă mișcare (ex: senzor revine la 0) → stingere după ceva timp
    when(room.ruleEngine, [](const Event& e) {
        return e.type == "sensor.motion" && e.value == 0;
    }).Do([]() {
        // aici poți adăuga delay inteligent (de ex. cu program/check)
        room.mainLight.fadeTo(10);
    });

    // 3. Low power → lumină off și mesaj vocal
    when(room.ruleEngine, [](const Event& e) {
        return e.type == "system.low_power";
    }).Do([]() {
        room.mainLight.off();
        room.media.tts("Mod economisire energie activat");
    });

    // 4. Telefonul cere scena "evening"
    when(room.ruleEngine, [](const Event& e) {
        return e.type == "phone.command" && e.source == "scene.evening";
    }).Do([]() {
        room.sceneManager.load("evening");
    });

    // 5. Telefonul cere scena "night"
    when(room.ruleEngine, [](const Event& e) {
        return e.type == "phone.command" && e.source == "scene.night";
    }).Do([]() {
        room.sceneManager.load("night");
    });

    // 6. Telefonul cere scena "focus"
    when(room.ruleEngine, [](const Event& e) {
        return e.type == "phone.command" && e.source == "scene.focus";
    }).Do([]() {
        room.sceneManager.load("focus");
    });

    // 7. Intrare utilizator în cameră → welcome_home
    when(room.ruleEngine, [](const Event& e) {
        return e.type == "location.entered";
    }).Do([]() {
        room.sceneManager.load("welcome_home");
    });

    // 8. Scene logică: după ce se încarcă "evening" → mesaj scurt
    when(room.ruleEngine, [](const Event& e) {
        return e.type == "scene.loaded" && e.source == "evening";
    }).Do([]() {
        room.media.tts("Scena evening este activa");
    });
}

// ---------- HANDLERE DE EVENIMENTE ----------

void setupEventHandlers() {
    room.eventBus.on([](Event e) {
        // Debug serial (opțional)
        // Serial.print("[EVENT] "); Serial.print(e.type); Serial.print(" from "); Serial.print(e.source); Serial.print(" val="); Serial.println(e.value);

        // Interfon sună
        if (e.type == "intercom.call_incoming") {
            room.media.notify("ding_dong");
            room.mainLight.fadeTo(80);
        }

        // Cerere deschidere ușă din interfon
        if (e.type == "intercom.door_open_request") {
            // aici poți pune logică de acces
            room.access.approve(room.eventBus, "intercom");
            room.yala.on();
            room.media.tts("Usa este deschisa");
        }

        // Ușa s-a deschis
        if (e.type == "intercom.door_opened") {
            room.media.notify("door_open");
        }

        // Sistemul bootează
        if (e.type == "system.boot") {
            room.media.tts("Smart Room pornita");
        }

        // Erori (poți extinde SystemMonitor)
        if (e.type == "system.overheat") {
            room.media.notify("alert");
            room.mainLight.off();
        }
    });
}

// ---------- SETUP PRINCIPAL ----------

void setup() {
    // Serial doar pentru debug / protocol
    Serial.begin(115200);
    delay(1000);

    room.begin();
    setupScenes();
    setupRules();
    setupEventHandlers();

    // Pornim cu o scenă implicită
    room.sceneManager.load("evening");
}

// ---------- LOOP PRINCIPAL ----------

void loop() {
    room.loop();

    // Exemplu: simulezi un low power (de test)
    // if (millis() > 60000 && millis() < 61000) {
    //     room.systemMonitor.lowPower(4.3);
    // }

    // Exemplu: simulezi apel interfon (de test)
    // if (millis() > 30000 && millis() < 31000) {
    //     room.intercom.incomingCall();
    // }

    // Restul este gestionat de MainBoard
}
//-------------------------------------------------------------------------------------------------------------------------------------