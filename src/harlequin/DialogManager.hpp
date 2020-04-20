#ifndef TREFUSISENGINE_DIALOGMANAGER_HPP
#define TREFUSISENGINE_DIALOGMANAGER_HPP

#include <queue> 
#include <string>

struct Dialog {
    std::string owner;
    std::string text;
};

class DialogManager
{
private:
    static std::queue<Dialog> dialogs;
    static DialogManager* instance;
    static bool isInitialised;
    static void InitialiseIfNotAlready();
    DialogManager();
public:
    /**
     * Add a dialog to the dialog queue.
     * @param dialog dialog object conteining the dialog.
     */
    static void addDialog(Dialog dialog);
    /**
     * Return the next dialog in the dialog queue if there is one.
     * @return the next dialog, or if there isn't any, null.
     */
    static Dialog nextDialog();
    /**
     * Check if there are any more dialogs.
     */
    static bool hasNextDialog();
};


#endif