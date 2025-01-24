def rebuid_message(parts):
    """ unique first character for all parts """
    mp = dict()
    for i in parts:
        mp[i[0]] = i
        mp[i[-1]] = i

