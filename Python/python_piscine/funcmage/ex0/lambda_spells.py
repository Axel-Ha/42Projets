from typing import Any


def artifact_sorter(artifacts: list[dict[str, Any]]) -> list[dict[str, Any]]:
    return sorted(artifacts, key=lambda s: s['power'], reverse=True)


def power_filter(mages: list[dict[str, Any]],
                 min_power: int) -> list[dict[str, Any]]:
    return list(filter(lambda s: (s['power'] >= min_power), mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda x: '* '+x+' *', spells))


def mage_stats(mages: list[dict[str, Any]]) -> dict[str, Any]:
    return {'max_power': max(mages, key=lambda x: x['power'])['power'],
            'min_power': min(mages, key=lambda x: x['power'])['power'],
            'avg_power': round((sum(map(lambda x:
                                        x['power'], mages)) / len(mages)), 2)}


if __name__ == "__main__":
    artifacts = [{'name': 'Shadow Blade', 'power': 99, 'type': 'armor'},
                 {'name': 'Earth Shield', 'power': 109, 'type': 'armor'}, {
        'name': 'Shadow Blade', 'power': 83, 'type': 'weapon'},
        {'name': 'Earth Shield', 'power': 82, 'type': 'focus'}]
    mages = [{'name': 'Ember', 'power': 71, 'element': 'shadow'},
             {'name': 'Luna', 'power': 90, 'element': 'light'}, {
                 'name': 'Alex', 'power': 99, 'element': 'water'},
             {'name': 'Sage', 'power': 52, 'element': 'light'},
             {'name': 'Phoenix', 'power': 91, 'element': 'wind'}]
    spells = ['fireball', 'blizzard', 'tornado', 'earthquake']
    print(artifact_sorter(artifacts))
    print(power_filter(mages, 91))
    print(spell_transformer(spells))
    print(mage_stats(mages))
