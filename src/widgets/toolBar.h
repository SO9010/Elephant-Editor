#include "../window.h"
#include "../ui/button.h"

class toolBar{
public:
    toolBar();
    ~toolBar();
    
    static SDL_Color    primaryColour;
    tools               toolCollection;
    void                renderToolBar(windowProperty wP, boardPorperties bP);
    void                updateTools();
    button tool;

private:
    void                changeCursor(std::string cursor, int offSet);
    void                changeCursor(std::string cursor, int offSetX, int offSetY);
    void                changeCursor(std::string cursor);

    void                zoomIn();
    void                zoomOut();
    void                moveTool();
    void                squareTool();
    void                triangelTool();
    void                circleTool();
    void                penTool();
    void                eraserTool();
};