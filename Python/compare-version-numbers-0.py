class Solution:
    # @param {string} version1
    # @param {string} version2
    # @return {integer}

    def compareVersion(self, version1, version2):
        def isAllZero(version):
            return len(filter(lambda x: int(x) == 0, version)) == len(version)

        version1 = version1.split('.')
        version2 = version2.split('.')

        while version1 or version2:
            if not version1:
                if isAllZero(version2):
                    return 0
                return -1
            if not version2:
                if isAllZero(version1):
                    return 0
                return 1

            v1 = int(version1[0])
            v2 = int(version2[0])

            if v1 > v2:
                return 1
            if v2 > v1:
                return -1

            version1 = version1[1:]
            version2 = version2[1:]

        return 0
