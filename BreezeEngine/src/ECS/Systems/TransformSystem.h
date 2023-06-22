#include "../ECSManager.h"

class TransformSystem
{
public:
    void Update(ECSManager& ecs);

private:
    float dt = 0.1f;
};
