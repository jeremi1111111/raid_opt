#pragma once

class player_info
{
	int raid_dmg;
	int jade_bonus;
	int season_bonus;
	int dust;
	int wildcards;
public:
	player_info(int raid_dmg, int jade_bonus, int season_bonus, int dust, int wildcards)
		: raid_dmg(raid_dmg), jade_bonus(jade_bonus), season_bonus(season_bonus), dust(dust), wildcards(wildcards)
	{}
	double get_base_dmg()
	{
		return raid_dmg * (1 + 0.01 * (jade_bonus + season_bonus));
	}
};