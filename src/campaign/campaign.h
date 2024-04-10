#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include <stddef.h>
#include <stdint.h>

#define CAMPAIGN_NO_RANK -1

typedef struct {
    const uint8_t *name;
    const uint8_t *author;
    const uint8_t *description;
    int number_of_missions;
    int starting_rank;
} campaign_info;

typedef struct {
    int id;
    int x;
    int y;
    const uint8_t *name;
    const uint8_t *description;
    const char *path;
    const char *briefing_image_path;
    const char *victory_image_path;
    const char *fanfare;
} campaign_scenario;

typedef struct {
    const uint8_t *title;
    const char *intro_video;
    const char *background_image;
    int next_rank;
    int max_personal_savings;
    int first_scenario;
    int total_scenarios;
} campaign_mission_info;

/**
 * Loads a campaign from the filename.
 * @param filename The filename to load. Can be a directory or a file with the .campaign extension.
 * @return 1 if the campaign was loaded, 0 if there was a problem.
 */
int campaign_load(const char *filename);

/**
 * Checks if the campaign is active.
 * @return 1 if the campaign is active, 0 otherwise.
 */
int campaign_is_active(void);

/**
 * Gets the campaign filename.
 * @return The campaign filename if the campaign is active, 0 otherwise.
 */
const char *campaign_get_name(void);

/**
 * Gets the basic info for the campaign.
 * @return A campaign_info struct with the data if successful, 0 otherwise.
 */
const campaign_info *campaign_get_info(void);

/**
 * Checks if a file exists in the current campaign.
 * @param filename The filename to check.
 * @return 1 if the file exists, 0 otherwise.
 */
int campaign_has_file(const char *filename);

/**
 * Loads a file from the campaign.
 * @param filename The filename to load.
 * @param length The length of the file.
 * @return A pointer to the file data if successful, 0 otherwise. The caller is responsible for freeing the memory.
 */
uint8_t *campaign_load_file(const char *filename, size_t *length);

/**
 * Loads a campaign scenario with the specified ID.
 * @param scenario_id The ID of the scenario to load.
 * @return 1 if the scenario was loaded successfully, 0 otherwise.
 */
int campaign_load_scenario(int scenario_id);

/**
 * Gets the current mission info.
 * @param scenario_id The scenario id.
 * @return A pointer to the mission info if successful, 0 otherwise.
 */
const campaign_mission_info *campaign_get_current_mission(int scenario_id);

 /**
 * Gets the next mission from the campaign.
 * @param last_scenario_id The last played scenario.
 * @return A pointer to the first mission whose first scenario is higher than last_scenario_id,
 * or 0 if there's an error or if there are no new missions.
 */
const campaign_mission_info *campaign_get_next_mission(int last_scenario_id);

/**
 * Gets a scenario from the campaign.
 * @param scenario_id The scenario id.
 * @return A pointer to the scenario with the given id, or 0 if there's an error.
 */
const campaign_scenario *campaign_get_scenario(int scenario_id);

/**
 * Suspends the campaign.
 */
void campaign_suspend(void);

/**
 * Restores a suspended campaign.
 */
void campaign_restore(void);

/**
 * Clears the campaign data.
 */
void campaign_clear(void);

#endif // CAMPAIGN_H
