#include "screen_bounds_system.h"
#include "../components.h"
#include "../resources.h"

void ScreenBoundsSystem::Run(entt::registry &registry) {
  WindowDimensions dimensions = registry.ctx<WindowDimensions>();
  auto view = registry.view<Player, Transform>();

  for (auto entitty : view) {
    auto &transform = registry.get<Transform>(entitty);
    if (transform.Left() < 0.0f) {
      transform.SetLeft(0.0f);
    }
    if (transform.Right() > dimensions.width) {
      transform.SetRight(dimensions.width);
    }

    if (transform.Top() < 0.0f) {
      transform.SetTop(0.0f);
    }
    if (transform.Bottom() > dimensions.height) {
      transform.SetBottom(dimensions.height);
    }
  }
}
