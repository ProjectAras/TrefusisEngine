struct SphericalLightSource {
    int lightValue; // PLEASE I BEG YOU DON'T MAKE THIS NEGATIVE
    // I HAVE NO WAY TO ENFORCE IT ON THE CODE BUT FOR THE LOVE
    // OF EVERYTHING HOLY DO NOT MAKE THIS VALUE NEGATIVE!!!
};

struct RadialLightSource {
    int lightValue;
    double startRad;
    double endRad;
};

class LightingManager {
private:
    int **BrightnessCells;
    static LightingManager *manager;
    /**
     * Insantiate a LightingManager instance, given:
     * @param width of the screen.
     * @param height of the screen.
     */
    LightingManager(int width, int height);
    /**
     * Destroy a lighting manager instance and deallocate its
     * allocated resources.
     */
    ~LightingManager();
public:
    /**
     * Update the brightness values, given
     * @param modifier A negative or positive modifier
     * that will be applied to the cells.
     * @param i i coordinate of the matrix.
     * @param j j coordinate of the matrix.
     */
    void Update(int i, int j, int modifier);
    /**
     * Get the current Lighting Manager Instance.
     */
    static inline LightingManager *GetLightingManager();
    /**
     * Must be called prior to anything else.
     * Initialise the lighting manager with:
     * @param width of the screen.
     * @param height of the screen.
     * @return the freshly initialised LightingManager.
     */
    static LightingManager *InitialiseLightingManager(int width, int height);
    static void addLightSource(int i, int j, SphericalLightSource lightSource);
    static void addLigthSource(int i, int j, RadialLightSource lightSource);
};