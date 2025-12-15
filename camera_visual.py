import pygame
import numpy as np

# ---------------------------
# Camera class
# ---------------------------
class Camera:
    def __init__(self):
        self.pos_x = 300
        self.pos_y = 300
        self.view_angle = np.pi / 2
        self.move_fwd = False
        self.move_back = False
        self.truck_left = False
        self.truck_right = False
        self.rotate_left = False
        self.rotate_right = False

# ---------------------------
# Apply motion
# ---------------------------
def apply_motion(cam):
    speed = 1.0
    angle_speed = 0.02

    cos_a = np.cos(cam.view_angle)
    sin_a = np.sin(cam.view_angle)

    if cam.rotate_left:
        cam.view_angle -= angle_speed
    if cam.rotate_right:
        cam.view_angle += angle_speed

    cam.view_angle %= 2 * np.pi

    if cam.move_back:
        cam.pos_x += cos_a * speed
        cam.pos_y += sin_a * speed
    if cam.move_fwd:
        cam.pos_x -= cos_a * speed
        cam.pos_y -= sin_a * speed
    if cam.truck_right:
        cam.pos_x += sin_a * speed
        cam.pos_y -= cos_a * speed
    if cam.truck_left:
        cam.pos_x -= sin_a * speed
        cam.pos_y += cos_a * speed

# ---------------------------
# Raycasting
# ---------------------------
def cast_rays(cam, walls, num_rays=20, max_distance=300):
    rays = []
    fov = np.pi / 3  # 60 deg
    start_angle = cam.view_angle - fov/2
    ray_angles = []
    for i in range(num_rays):
        ray_angle = start_angle + i*(fov/num_rays)
        ray_dx = np.cos(ray_angle)
        ray_dy = np.sin(ray_angle)
        ray_end = np.array([cam.pos_x, cam.pos_y], dtype=float)
        for step in range(max_distance):
            test_x = int(ray_end[0])
            test_y = int(ray_end[1])
            hit = False
            for wall in walls:
                if wall.collidepoint(test_x, test_y):
                    hit = True
                    break
            if hit:
                ray_end = np.array([test_x, test_y])
                break
            ray_end += [ray_dx, ray_dy]
        rays.append(ray_end)
        ray_angles.append(ray_angle)
    return rays, ray_angles

# ---------------------------
# Draw
# ---------------------------
def draw_camera(screen, cam, walls):
    screen.fill((30,30,30))
    origin = (int(cam.pos_x), int(cam.pos_y))

    # Axes
    pygame.draw.line(screen, (200,200,200), (0, origin[1]), (600, origin[1]), 1)
    pygame.draw.line(screen, (200,200,200), (origin[0],0), (origin[0],600), 1)

    # Walls
    for wall in walls:
        pygame.draw.rect(screen, (150,150,150), wall)

    # Forward / strafe vectors
    fwd = (int(cam.pos_x - np.cos(cam.view_angle)*50),
           int(cam.pos_y - np.sin(cam.view_angle)*50))
    pygame.draw.line(screen, (0,0,255), origin, fwd, 4)
    screen.blit(font.render(f"{cam.view_angle:.2f} rad", True, (0,0,255)), (fwd[0]+5, fwd[1]))

    right_angle = (cam.view_angle + np.pi/2) % (2*np.pi)
    right = (int(cam.pos_x + np.sin(cam.view_angle)*50),
             int(cam.pos_y - np.cos(cam.view_angle)*50))
    pygame.draw.line(screen, (255,0,0), origin, right, 4)
    screen.blit(font.render(f"{right_angle:.2f}", True, (255,0,0)), (right[0]+5, right[1]))

    left_angle = (cam.view_angle - np.pi/2) % (2*np.pi)
    left = (int(cam.pos_x - np.sin(cam.view_angle)*50),
            int(cam.pos_y + np.cos(cam.view_angle)*50))
    pygame.draw.line(screen, (0,255,0), origin, left, 4)
    screen.blit(font.render(f"{left_angle:.2f}", True, (0,255,0)), (left[0]+5, left[1]))

    pygame.draw.circle(screen, (255,255,255), origin, 5)

    # Alpha arc
    arc_radius = 40
    num_points = 50
    angles = np.linspace(0, cam.view_angle, num_points)
    arc_points = [(int(cam.pos_x + arc_radius*np.cos(a)),
                   int(cam.pos_y - arc_radius*np.sin(a))) for a in angles]
    if len(arc_points) > 1:
        pygame.draw.lines(screen, (200,0,200), False, arc_points, 2)

    # Rays
    rays, ray_angles = cast_rays(cam, walls)
    for ray_end, ray_angle in zip(rays, ray_angles):
        pygame.draw.line(screen, (255,255,0), origin, (int(ray_end[0]), int(ray_end[1])), 1)
        # Optional: display angle of each ray (small)
        # screen.blit(font.render(f"{ray_angle:.2f}", True, (255,255,0)), (int(ray_end[0]), int(ray_end[1])))

    # Display camera alpha
    screen.blit(font.render(f"α = {cam.view_angle:.2f} rad", True, (200,200,200)), (10,10))

# ---------------------------
# Main
# ---------------------------
pygame.init()
screen = pygame.display.set_mode((600,600))
pygame.display.set_caption("Camera with angles overlay")
clock = pygame.time.Clock()
font = pygame.font.SysFont(None, 20)

cam = Camera()
running = True

# Walls
walls = [
    pygame.Rect(100, 100, 100, 20),
    pygame.Rect(400, 150, 20, 200),
    pygame.Rect(200, 400, 300, 20)
]

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_w: cam.move_fwd = True
            if event.key == pygame.K_s: cam.move_back = True
            if event.key == pygame.K_a: cam.truck_left = True
            if event.key == pygame.K_d: cam.truck_right = True
            if event.key == pygame.K_LEFT: cam.rotate_left = True
            if event.key == pygame.K_RIGHT: cam.rotate_right = True

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_w: cam.move_fwd = False
            if event.key == pygame.K_s: cam.move_back = False
            if event.key == pygame.K_a: cam.truck_left = False
            if event.key == pygame.K_d: cam.truck_right = False
            if event.key == pygame.K_LEFT: cam.rotate_left = False
            if event.key == pygame.K_RIGHT: cam.rotate_right = False

    apply_motion(cam)
    draw_camera(screen, cam, walls)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
