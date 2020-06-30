class Solution(object):
    def validIPAddress(self, ip):
        """
        :type IP: str
        :rtype: str
        """
        ipv4 = 0
        for i in range(len(ip)):
            if ip[i] == '.':
                ipv4 = 1
                # print "gh"
                break
            
        if ipv4 == 1:
            s = ip.split('.')
            if len(s) != 4:
                # print"A"
                return "Neither"
            else:
                for j in s:
                    if len(j) == 0 or len(j) > 3:
                        # print "B"
                        return "Neither"
                    for k in j:
                        if not (k >= '0' and k <= '9'):
                            return "Neither"
                    if int(j) < 0  or int(j) > 255:
                        # print "C"
                        return "Neither"
                    if j[0] == '0' and len(j) > 1:
                        # print "D"
                        return "Neither"
            
            return "IPv4"
        
        else:
            s = ip.split(':')
            if len(s) != 8:
                return "Neither"
            else:
                for j in s:
                    if len(j) == 0 or len(j) > 4:
                        return "Neither"
                    for k in j:
                        if not (k >= '0' and k <='9' or k >= 'a' and k <= 'f' or k >='A' and k <= 'F') :
                            return "Neither"
            
            return "IPv6"
                    
                    
