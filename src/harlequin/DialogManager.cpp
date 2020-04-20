#include "DialogManager.hpp"

std::queue<Dialog> DialogManager::dialogs;
bool DialogManager::isInitialised = false;
DialogManager* DialogManager::instance = nullptr;


DialogManager::DialogManager () {

}

void DialogManager::InitialiseIfNotAlready() {
    if (isInitialised == false) {
        instance = new DialogManager();
        isInitialised == true;
    }
}

Dialog DialogManager::nextDialog() {
    InitialiseIfNotAlready();
    Dialog dialog = dialogs.front();
    dialogs.pop();
    return dialog;
}

bool DialogManager::hasNextDialog() {
    InitialiseIfNotAlready();
    Dialog dialog = dialogs.front();
    return &dialog != nullptr;
}

void DialogManager::addDialog(Dialog dialog) {
    InitialiseIfNotAlready();
    dialogs.push(dialog);
}