package net.violet.probes;

import javax.management.openmbean.CompositeData;
import javax.management.openmbean.OpenDataException;

public interface EventProbeMBean {

	CompositeData getEventPingStats() throws OpenDataException;
}
